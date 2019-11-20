#include "stdafx.h"
#include "FlakyTestRunner.h"

FlakyTestRunner::FlakyTestRunner(const ITestRunner::Ptr& testRunner,
								 std::int32_t maxExecutions)
	: _testRunner(testRunner)
	, _maxExecutions(maxExecutions)
{
	if (nullptr == _testRunner)
		throw std::invalid_argument("testRunner is expected to not be nullptr");
	if (_maxExecutions < 2)
		throw std::invalid_argument("maxExecutions is expected to be 2 or greater");
}

TestRunResult FlakyTestRunner::Run(const std::vector<TestMethod::Ptr>& methods)
{
	std::unordered_map<TestMethod::Ptr, TestResult> currentResults;
	std::vector<TestMethod::Ptr> methodsToExecute = methods;

	for(std::int32_t i = 0; i < _maxExecutions; ++i)
	{
		auto result = _testRunner->Run(methodsToExecute);

		methodsToExecute.clear();
		for(const auto& testResult : result.AllTests())
		{
			// The goal is to re-run ONLY those tests which have failed and to be satisfied
			// with all other tests which already succeeded.
			if (testResult.IsFailure())
			{
				methodsToExecute.push_back(testResult.TestMethod());
			}

			currentResults[testResult.TestMethod()] = testResult;
		}
	}

	std::vector<TestResult> finalResults(currentResults.size());
	for(const auto& pair : currentResults)
		finalResults.push_back(pair.second);

	return TestRunResult(finalResults);
}

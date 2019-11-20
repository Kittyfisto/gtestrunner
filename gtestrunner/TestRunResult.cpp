#include "stdafx.h"
#include "TestRunResult.h"

TestRunResult::TestRunResult(const std::vector<TestResult>& testResults)
	: _testResults(testResults)
{}

std::size_t TestRunResult::NumSuccesses() const
{
	return std::count_if(_testResults.begin(), _testResults.end(), [](const TestResult& result) -> bool {return result.IsSuccess();});
}

std::size_t TestRunResult::NumFailures() const
{
	return std::count_if(_testResults.begin(), _testResults.end(), [](const TestResult& result) -> bool {return result.IsFailure();});
}

std::size_t TestRunResult::NumInconclusive() const
{
	return std::count_if(_testResults.begin(), _testResults.end(), [](const TestResult& result) -> bool {return result.IsInconclusive();});
}

const std::vector<TestResult>& TestRunResult::AllTests() const
{
	return _testResults;
}

std::vector<TestResult> TestRunResult::FailedTests() const
{
	std::vector<TestResult> failed;
	std::copy_if(_testResults.begin(), _testResults.end(), failed.end(), [](const TestResult& result) -> bool { return result.IsFailure();});
	return failed;
}

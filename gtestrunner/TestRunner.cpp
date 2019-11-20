#include "stdafx.h"
#include "TestRunner.h"

TestRunResult TestRunner::Run(const std::vector<TestMethod::Ptr>& methods)
{
	std::unordered_map<TestExecutable::Ptr, std::vector<TestMethod::Ptr>> methodsByExecutable;
	for(const auto& method : methods)
	{
		methodsByExecutable[method->TestExecutable()].push_back(method);
	}

	std::vector<TestResult> results(methods.size());
	for(const auto& pair : methodsByExecutable)
	{
		auto tmp = Run(pair.first, pair.second);
		results.insert(results.end(), tmp.begin(), tmp.end());
	}

	return results;
}

std::vector<TestResult> TestRunner::Run(const TestExecutable::Ptr&,
										const std::vector<TestMethod::Ptr>&)
{
	// TODO:
	// * Build command-line
	// * Invoke process
	// * Parse results
	throw std::exception("not implemented");
}

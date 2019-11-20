#pragma once

#include "ITestRunner.h"

/**
 * @brief Responsible for executing one or more tests in a parallel manner in order to reduce total execution time.
 */
class TestRunner final
	: public ITestRunner
{
public:

	/**
	 * @brief Executes the given test methods in a serial manner and returns their result
	 */
	TestRunResult Run(const std::vector<TestMethod::Ptr>& methods) override;

private:

	static std::vector<TestResult> Run(const TestExecutable::Ptr& testExecutable,
									   const std::vector<TestMethod::Ptr>& methods);
};
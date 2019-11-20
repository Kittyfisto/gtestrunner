#pragma once

#include "ITestRunner.h"

/**
 * @brief Responsible for executing one or more tests
 */
class FlakyTestRunner final
	: public ITestRunner
{
public:

	/**
	 * @brief 
	 * @param testRunner      The test runner which is used to run and re-run tests if necessary
	 * @param maxExecutions   The maximum number of times a single test is run before it is marked as having failed
	 */
	FlakyTestRunner(const ITestRunner::Ptr& testRunner,
					std::int32_t maxExecutions);

	/**
	 * @brief Executes the given test methods in a serial manner and returns their result
	 */
	TestRunResult Run(const std::vector<TestMethod::Ptr>& methods) override;

private:

	const ITestRunner::Ptr _testRunner;
	const std::int32_t _maxExecutions;
};
#pragma once

#include "ITestRunner.h"

class ParallelTestRunner final
	: public ITestRunner
{
public:

	/**
	 * @brief 
	 * @param testRunner         The test runner to execute the individual tests with - may be called in parallel
	 * @param maxParallelTests   The maximum number of tests which shall be executed in parallel at a single point in time
	 */
	ParallelTestRunner(const ITestRunner::Ptr& testRunner,
					   std::int32_t maxParallelTests);

	/**
	 * @brief Executes the given test methods in a parallel manner and returns their result
	 */
	TestRunResult Run(const std::vector<TestMethod::Ptr>& methods) override;

private:

	ITestRunner::Ptr _testRunner;
	std::int32_t _maxParallelTests;
};

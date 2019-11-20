#pragma once

#include <vector>

#include "TestResult.h"

/**
 * @brief Represents the result of a test run (in which 0 or more tests have been executed)
 */
class TestRunResult final
{
public:

	TestRunResult(const std::vector<TestResult>& testResults);

	/**
	 * @brief The number of tests which were executed successfully
	 */
	std::size_t NumSuccesses() const;

	/**
	 * @brief The number of tests who's result is failure
	 */
	std::size_t NumFailures() const;

	/**
	 * @brief The number of tests who's result is inconclusive
	 */
	std::size_t NumInconclusive() const;

	/**
	 *@brief Returns the list of all tests
	 */
	const std::vector<TestResult>& AllTests() const;

	/**
	 * @brief Returns the list of tests which failed
	 */
	std::vector<TestResult> FailedTests() const;

private:

	std::vector<TestResult> _testResults;
};
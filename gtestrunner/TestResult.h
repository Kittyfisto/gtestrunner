#pragma once

#include "TestMethod.h"
#include "Result.h"

/**
 * @brief Represents the execution result of a single test method
 */
class TestResult final
{
public:

	TestResult() = default;
	TestResult(const TestMethod::Ptr& testMethod, Result result);

	/**
	 * @brief The method which was executed
	 */
	TestMethod::Ptr TestMethod() const;

	/**
	 * @brief True when the test was successful, false otherwise
	 */
	bool IsSuccess() const;

	/**
	 * @brief True when the test failed, false otherwise
	 */
	bool IsFailure() const;

	/**
	 * @brief True when the test execution was inconclusive, false otherwise
	 */
	bool IsInconclusive() const;

private:

	TestMethod::Ptr   _testMethod;
	Result            _result;
};
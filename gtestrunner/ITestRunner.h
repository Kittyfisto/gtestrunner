#pragma once

#include "TestRunResult.h"

/**
 * @brief The interface for a test runner which executes test methods in an unspecified fashion and returns a combined result
 */
class ITestRunner abstract
{
public:

	typedef std::shared_ptr<ITestRunner> Ptr;

	virtual ~ITestRunner() = default;

	virtual TestRunResult Run(const std::vector<TestMethod::Ptr>& methods) = 0;
};

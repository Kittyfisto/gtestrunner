#pragma once

#include <memory>
#include <string>
#include "TestExecutable.h"

/**
 * @brief Represents a single test method
 */
class TestMethod final
{
public:

	typedef std::shared_ptr<TestMethod> Ptr;

	TestMethod(const TestExecutable::Ptr& testExecutable,
			   const std::wstring& testName,
			   const std::wstring& methodName);

	TestExecutable::Ptr TestExecutable() const;
	const std::wstring& TestName() const;
	const std::wstring& MethodName() const;

private:

	const TestExecutable::Ptr _testExecutable;
	const std::wstring _testName;
	const std::wstring _methodName;
};
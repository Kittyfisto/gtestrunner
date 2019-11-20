#include "stdafx.h"
#include "TestMethod.h"

TestMethod::TestMethod(const TestExecutable::Ptr& testExecutable,
					   const std::wstring& testName,
					   const std::wstring& methodName)
	: _testExecutable(testExecutable)
	, _testName(testName)
	, _methodName(methodName)
{}

TestExecutable::Ptr TestMethod::TestExecutable() const
{
	return _testExecutable;
}

const std::wstring& TestMethod::TestName() const
{
	return _testName;
}

const std::wstring& TestMethod::MethodName() const
{
	return _methodName;
}

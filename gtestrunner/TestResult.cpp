#include "stdafx.h"
#include "TestResult.h"

TestResult::TestResult(const TestMethod::Ptr& testMethod, Result result)
	: _testMethod(testMethod)
	, _result(result)
{}

TestMethod::Ptr TestResult::TestMethod() const
{
	return _testMethod;
}

bool TestResult::IsSuccess() const
{
	return _result == Result::Success;
}

bool TestResult::IsFailure() const
{
	return _result ==  Result::Failure;
}

bool TestResult::IsInconclusive() const
{
	return _result == Result::Inconclusive;
}

#pragma once

#include "TestRunResult.h"

class ITestResultReader
{
public:

	typedef std::shared_ptr<ITestResultReader> Ptr;

	virtual ~ITestResultReader() = default;

	virtual TestRunResult Read(std::istream& stream) = 0;
};

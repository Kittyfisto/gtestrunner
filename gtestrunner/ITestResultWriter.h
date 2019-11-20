#pragma once

#include "TestRunResult.h"

class ITestResultWriter
{
public:

	typedef std::shared_ptr<ITestResultWriter> Ptr;

	virtual ~ITestResultWriter() = default;

	virtual void Write(const TestRunResult& result, std::ostream& stream) = 0;
};
#pragma once

#pragma once

#include "ITestResultWriter.h"

class ConsoleTestResultWriter final
	: public ITestResultWriter
{
public:

	void Write(const TestRunResult& result, std::ostream& stream) override;
};

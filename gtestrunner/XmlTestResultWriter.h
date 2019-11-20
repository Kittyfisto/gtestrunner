#pragma once
#include "ITestResultWriter.h"

class XmlTestResultWriter
	: public ITestResultWriter
{
public:

	void Write(const TestRunResult& result, std::ostream& stream) override;
};

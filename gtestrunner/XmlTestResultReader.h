#pragma once

#include "ITestResultReader.h"

class XmlTestResultReader final
	: public ITestResultReader
{
public:

	TestRunResult Read(std::istream& stream) override;
};

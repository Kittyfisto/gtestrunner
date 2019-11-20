#include "stdafx.h"
#include "TestExplorer.h"
#include "TestRunner.h"
#include "FlakyTestRunner.h"
#include "ConsoleTestResultWriter.h"
#include "XmlTestResultWriter.h"

void WriteXmlResult(TestRunResult result)
{
	XmlTestResultWriter xmlWriter;
	std::filesystem::path resultFilePath = "tests.xml";
	std::ofstream file(resultFilePath);
	xmlWriter.Write(result, file);
}

void WriteConsoleResult(TestRunResult result)
{
	ConsoleTestResultWriter consoleWriter;
	consoleWriter.Write(result, std::cout);
}

TestRunResult RunTests(std::vector<TestMethod::Ptr> testMethods)
{
	auto runner = std::make_shared<TestRunner>();
	auto flakyRunner = std::make_shared<FlakyTestRunner>(runner, 5);
	return flakyRunner->Run(testMethods);
}

int main()
{
	std::cout << "Hello World!\n";

	// TODO: Parse command line arguments to specify what shall be done
	auto workingDirectory = std::filesystem::current_path();
	const auto testExecutable = std::make_shared<TestExecutable>("foo.exe", workingDirectory);

	const TestExplorer explorer;
	const auto testMethods = explorer.ExploreTests(testExecutable);
	const auto result = RunTests(testMethods);

	WriteConsoleResult(result);
	WriteXmlResult(result);

	if (result.NumFailures() == 0)
		return 0;

	return 1;
}

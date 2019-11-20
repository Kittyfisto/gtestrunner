#include "stdafx.h"
#include "ParallelTestRunner.h"

ParallelTestRunner::ParallelTestRunner(const ITestRunner::Ptr& testRunner,
									   std::int32_t maxParallelTests)
	: _testRunner(testRunner)
	, _maxParallelTests(maxParallelTests)
{
	if (maxParallelTests < 1)
		throw std::invalid_argument("maxParallelTests is expected to be greater than 1");
}

TestRunResult ParallelTestRunner::Run(const std::vector<TestMethod::Ptr>&)
{
	// TODO: What kind of execution strategy should we pick?
	// Things to keep in mind:
	// * Tests belonging to the same test class should probably be executed in serial in the same process
	// * Executing a single test per process is probably a shitty solution as process start/teardown has a cost
	//   associated with it and it's not negligible when we're dealing with 10k tests or more
	throw std::exception("not implemented");
}

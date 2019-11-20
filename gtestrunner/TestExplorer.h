#pragma once

#include <vector>

#include "TestMethod.h"
#include "TestExecutable.h"

class TestExplorer final
{
public:

	/**
	 * @brief Explores the tests in the given (google) test executable
	 */
	std::vector<TestMethod::Ptr> ExploreTests(const TestExecutable::Ptr& executable) const;
};

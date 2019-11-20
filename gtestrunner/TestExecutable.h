#pragma once

#include <memory>
#include <filesystem>

/**
 * @brief Describes a test-executable who's tests shall be executed.
 */
class TestExecutable final
{
public:

	typedef std::shared_ptr<TestExecutable> Ptr;

	TestExecutable(const std::filesystem::path& path,
				   const std::filesystem::path& workingDirectory);

	const std::filesystem::path& ExecutablePath() const;
	const std::filesystem::path& WorkingDirectory() const;

private:

	std::filesystem::path _executablePath;
	std::filesystem::path _workingDirectory;
};

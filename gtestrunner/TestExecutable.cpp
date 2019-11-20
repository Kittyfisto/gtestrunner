#include "stdafx.h"
#include "TestExecutable.h"

TestExecutable::TestExecutable(const std::filesystem::path& path,
							   const std::filesystem::path& workingDirectory)
	: _executablePath(path)
	, _workingDirectory(workingDirectory)
{}

const std::filesystem::path& TestExecutable::ExecutablePath() const
{
	return _executablePath;
}

const std::filesystem::path& TestExecutable::WorkingDirectory() const
{
	return _workingDirectory;
}

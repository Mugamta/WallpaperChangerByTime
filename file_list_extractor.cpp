#include "file_list_extractor.h"

#include <iostream>

// https://nauco.tistory.com/5 를 참고하였다.

std::vector<std::string> FileListExtractor(std::string path) {
	path += "*.*";

	struct _finddata_t fd;
	intptr_t handle;

	std::vector<std::string> image_names;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)

		std::cout << "No file in directory!" << '\n';

	do

	{
		image_names.push_back(fd.name);

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);

	return image_names;
}
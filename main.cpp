#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	std::string action;

	//1

	if (action == "Show_current_path")
	{
		std::cout << "Current path is " << fs::current_path() << "\n\n";
	}

	//2

	if (action == "Show_files_of_current_path")
	{
		for (auto& p : fs::directory_iterator(fs::current_path()))
		{
			std::cout << p.path().filename() << "\n";
		}
	}

	//3

	if (action == "Create_a_new_path")
	{
		std::cout << "Enter a name of new path: ";
		std::string S1;
		std::getline(std::cin, S1);
		if (fs::exists(S1))
		{
			std::cout << "The path with this name is already exists.\n\n";
		}
		else
		{
			fs::create_directory(S1);
			std::cout << "Done.\n\n";
		}
	}

	//4

	if (action == "Show_the_size_of_the_file")
	{
		std::cout << "Enter a name of the file: ";
		std::string S2;
		std::getline(std::cin, S2);
		if (fs::exists(S2))
		{
			std::cout << fs::file_size(S2);
			std::cout << "\n\n";
		}
		else
		{
			std::cout << "The file with this name isn't exists.\n\n";
		}
	}

	//5

	if (action == "Copy_the_file")
	{
		fs::copy_file(S2, "Copy.txt");
	}

	//6

	if (action == "Delete_the_file")
	{
		fs::remove(S2);
	}
	//7

	if (action == "Delete_the_path")
	{
		std::cout << "Enter a name of deleted path: ";
		std::string S3;
		std::getline(std::cin, S3);
		fs::remove_all(S3);
		std::cout << "\n\n";
	}
	
	//8

	if (action == "Move_to_relative_path")
	{
		std::cout << "If you want to go forward enter 1, else enter 0: ";
		bool level;
		std::cin >> level;
		if (level == 1)
		{
			std::cout << "Enter a name of a needed path: ";
			std::string S4;
			std::getline(std::cin, S4);
			fs::current_path(S4);
			std::cout << "Current path is " << (fs::current_path()) << "\n\n";
		}
		else
		{
			std::cout << "Enter a name of a needed path: ";
			std::string S4;
			std::getline(std::cin, S4);
			fs::current_path(fs::current_path().remove_filename());
			std::cout << "Current path is " << fs::current_path() << "\n\n";
		}
	}

	//9
	if (action == "Rename_the_file")
	{
		std::cout << "Enter a name of a needed file: ";
		std::string S5;
		std::getline(std::cin, S5);
		if (fs::exists(S5))
		{
			std::cout << "Enter a new name of a needed file: ";
			std::string S6;
			std::getline(std::cin, S6);
			fs::rename(S5, S6);
			std::cout << "Done.\n\n";
		}
		else
		{
			std::cout << "The file with this name isn't exists.\n\n";
		}
	}

	if (action == "Rename_the_path")
	{
		std::cout << "Enter a name of a needed path: ";
		std::string S7;
		std::getline(std::cin, S7);
		if (fs::exists(S7))
		{
			std::cout << "Enter a new name of a needed path: ";
			std::string S8;
			std::getline(std::cin, S8);
			fs::rename(S7, S8);
			std::cout << "Done.\n\n";
		}
		else
		{
			std::cout << "The path with this name isn't exists.\n\n";
		}
	}

	//10

	if (action == "Move_the_file")
	{
		std::cout << "Enter a name of a needed file: ";
		std::string S9;
		std::getline(std::cin, S9);
		if (fs::exists(S9))
		{
			std::cout << "Enter a new name of a needed path: ";
			std::string S10;
			std::getline(std::cin, S10);
			fs::path current_path;
			fs::path new_path;
			current_path = fs::current_path();
			current_path /= S9;
			fs::current_path(S10);
			new_path = fs::current_path();
			new_path /= S10;
			fs::rename(current_path, new_path);
			std::cout << "Done.\n\n";
		}
		else
		{
			std::cout << "The file with this name isn't exists.\n\n";
		}
	}

	return 0;
}

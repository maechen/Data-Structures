#include "addEmployee.hpp"

int split(string input_string, char separator, string arr[], int arr_size)
{
    bool found = false;
    int count_separators = 0;
    int current_index = 0;
    int start_index = 0;
    int end_index = 0;

    // checking if empty string
    if(input_string == "")
    {
        return 0;
    }

    // look at every element
    for (int i = 0; i < input_string.length() - 1; i++)
    {
        // checking if there is delimiter
        if (input_string[i] == separator)
        { 
            found = true;
            count_separators++; // increase counter
        }
    }

    // if there's no delimiter
    if(found == false)
    {
        arr[0] = input_string; // sets first element as input_string
        return 1;
    }
    else if(count_separators + 1 > arr_size) // if there are more splits than array elements
    { 
        for(int i = 0; i <= input_string.length(); i++)
        {
            if (input_string[i] == separator || i == input_string.length()) // use delimiter and end of string position
            { 
                end_index = i;
                arr[current_index] = input_string.substr(start_index, end_index - start_index); // element in array becomes split using substring; end - start = length of substring
                current_index++;
                start_index = end_index + 1; // new start position after split
            }
        }
    return -1;
    }
    else
    {
        for(int i = 0; i <= input_string.length(); i++)
        {
            if (input_string[i] == separator || i == input_string.length())
            {
                end_index = i;
                arr[current_index] = input_string.substr(start_index, end_index - start_index);
                current_index++;
                start_index = end_index + 1;
            }
        }
    }

    return count_separators + 1; // number of split pieces
}

int main(int argc, char *argv[])
{
    // check for number of arguments
    if (argc < 2)
    {
        cout << "file name missing" << endl;
        return -1;
    }

    string fileName = argv[1]; // TODO 1: get the file name from the command line parameters
    employee array[4];

    // open the file
    ifstream myfile;
    myfile.open(fileName);

    string line;
    string name;
    string emailid;
    string birthday;
    int length = 0;

    if (myfile.is_open()) // check that this file exists
    {
        // TODO 2:  Read each line from the file
        //          for each line do the following
        //               extract name, extract email, exract birthday
        //               call the addAemployee function to add them in the array
        while (getline(myfile, line))
        {
            string arr[3];
            split(line, ',', arr, 3);
            name = arr[0];
            birthday = arr[1];
            emailid = arr[2];
            int next_index = addAnEmployee(array, name, emailid, birthday, length);
            length = next_index;
        }
    }
    else
    {
        cout << "err: can not open file" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "name:" << array[i].name << " email:" << array[i].email << " bday:" << array[i].birthday << endl;
    }

    return 0;
}
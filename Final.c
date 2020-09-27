
/* --------------------------------------------WORKING WITH JSON FILE IN C---------------------------------------------------------

	* Program to read a json file,parse and assign the inputs into a structure.
	
	* There are so many libraries for parsing a json file in c,here using json-c library ( https://github.com/json-c/json-c ).
	
	* So,initially have to install the library which we are using.
	
	* " sudo apt install libjson-c-dev " for installing the library

	* The parsed contents of json file is in structure by default.i.e, the return type of the parse function is struct.

	* As the return type of the parse function is already in structure,a function is defined to print the contents parsed from Json file.

*/

#include<stdio.h>
#include<json-c/json.h> //Include the the library which we are using
#include<string.h>
#include<stdlib.h>

void json_parse_array(json_object * json_obj) 
{
	enum json_type type;//Declare type as a json_type
	
	int array_len,i;
	
	struct json_object * object_value;

	json_object_object_foreach(json_obj, key, val)//Iterates over the array
	{
		json_obj = json_object_object_get(json_obj, key);//Returns json_object of particular key

		array_len = json_object_array_length(json_obj);//Returns the array length

		printf("Number of objects in the file:  %d\n\n",array_len);

		for (i=0; i< array_len; i++)
		{
			object_value = json_object_array_get_idx(json_obj, i);//Return the element in the specific index or id

			printf("value[%d]: %s\n\n",i, json_object_get_string(object_value)); // String value of the element is displayed
		}
	}
	
}

int main() 
{
	FILE *fp; //Declare a file pointer for opening the json file.

	char buffer[1024]; // Declare a buffer to store the contents of the opened file.

	struct json_object *j_obj; // Define json objects in order to store the parsed json values.
	
	fp = fopen("json_test.json","r"); // Open the Json file and read into the buffer

	fread(buffer, 2000 , 1, fp);

	fclose(fp); //As the json file is already read in the buffer,we can close the file pointer

	j_obj = json_tokener_parse(buffer);//Parse the json file contents into a structure,Here the json object j_obj is in structure format.

	json_parse_array(j_obj);// Json file used is array of nested objects,so call the parse_array function to get the objects.

}



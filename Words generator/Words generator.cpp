#include<iostream>
#include<cstdlib>
using namespace std;

enum en_char_type { capital_letters = 1, small_letters = 2, symbols = 3, alpha_numeric = 4 };

// ÇáÍÕæá Úáì ÑŞã Çæ ÍÑİ Çæ ÑãÒ ÚÔæÇÆí  . 
char get_random_char(en_char_type type)
{
	switch (type)
	{
	case capital_letters:
		return char(rand() % 26 + 65);

	case small_letters:
		return char(rand() % 26 + 97);

	case symbols:
		return char(rand() % 15 + 33);

	case alpha_numeric:
		if (rand() % 2 == 0)
			return char(rand() % 26 + 65); // ÍÑİ

		else
			return char(rand() % 10 + 48); // ÑŞã

	default:
		return 'E';

	}
}

// ÊæáíÏ ßáãÉ ÚÔæÇÆíÉ ãä ÚÏÏ ÇÍÑİ ãÍÏÏ  .
string generate_word(en_char_type type, int number_of_chars)
{
	string word;

	for (int i = 1; i <= number_of_chars; i++)
	{
		word += get_random_char(type);
	}
	return word;
}

// ÊæáíÏ ãİÊÇÍ ÊãÑíÑ ãä ÚÏÏ ßáãÇÊ ãÍÏÏÉ æÇÍÑİ ãÍÏÏÉ .
string generate_key(en_char_type type, int number_of_chars, int number_of_words)
{
	string key;

	for (int i = 1; i <= number_of_words; i++)
	{
		key += generate_word(type, number_of_chars);
		if (i < number_of_words)
		{
			key += "-";
		}
	}

	return key;
}

// ÊæáíÏ ÇßËÑ ãä ãİÊÇÍ ÊãÑíÑ ãä ÚÏÏ ßáãÇÊ ãÍÏÏÉ æÇÍÑİ ãÍÏÏÉ . 
void generate_keys(en_char_type type, int number_of_chars, int number_of_words, int number_of_keys)
{

	cout << "\n\n";

	for (int i = 1; i <= number_of_keys; i++)
	{
		cout << "key [ " << i << " ] : ";
		cout << generate_key(type, number_of_chars, number_of_words);
		cout << "\n";
	}
}

// ŞÑÇÁÉ ÇáãÚØíÇÊ .
void read_info(int& keys, int& word, int& chr, en_char_type& char_type)
{

	int choose_type;

	cout << "\nHow much do you want  keys number ? ";
	cin >> keys;

	cout << "\nHow much do you want  words number ? ";
	cin >> word;

	cout << "\nHow much do you want  letters number ? ";
	cin >> chr;

	cout << "\nWhat do you want char_type : capital_letters[1] , small_letters[2] , symbols[3] , alpha_numeric[4] ?";
	cin >> choose_type;

	char_type = en_char_type(choose_type);
}

// ÊäİíĞ ÇáÈÑäÇãÌ .
void app_generate_keys()
{
	int  keys, word, chr;
	en_char_type char_type;

	read_info(keys, word, chr, char_type);

	generate_keys(char_type, chr, word, keys);

}

int main()
{

	srand((unsigned)time(NULL));

	app_generate_keys();


}

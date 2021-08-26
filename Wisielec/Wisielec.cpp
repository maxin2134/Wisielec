#include <iostream>
#include <ctime>

const int NUM = 26;
const std::string wordlist[NUM] = { "agrest", "bigos", "czara", "drewno", "ekipa", "figura", "gorycz", "hiena", "iskra"
                                  , "junior", "krata", "lizak", "miska", "nurek", "obuwie", "pisak", "rozum", "smalec",
                                    "taryfa", "umiar", "video", "welon", "yeti", "zalew", "zimno", "zapas" };

int main()
{
    std::srand(std::time(0));
    char play;
    std::cout << "Czy chcesz zagrać w wisielca? <t/n> ";
    std::cin >> play;
    play = tolower(play);
    while (play == 't')
    {
        std::string target = wordlist[std::rand() % NUM];
        int length = target.length();
        std::string attempt(length, '-');
        std::string badchars = "";
        int guesses = 6;
        std::cout << "Zgadnij słowo. Ma ono: " << length << " liter. Możesz zgadywać \n" <<
            "po jednej literze naraz. Możesz pomylić się " << guesses << " razy.\n";
        std::cout << "Twoje słowo to: " << attempt << std::endl;
        while (guesses > 0 && attempt != target)
        {
            char letter;
            std::cout << "Zgadnij literę: ";
            std::cin >> letter;
            if (badchars.find(letter) != std::string::npos || attempt.find(letter) != std::string::npos)
            {
                std::cout << "Ta litera już była. Spróbuj innej.\n";
                continue;
            }

            int loc = target.find(letter);
            if (loc == std::string::npos)
            {
                std::cout << "Nie ma tkaiej litery! \n";
                --guesses;
                badchars += letter;
            }
            else
            {
                std::cout << "Poprawna litera!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc + 1);
                while (loc != std::string::npos)
                {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc + 1);
                }
            }
            std::cout << "Twoje słowo: " << attempt << std::endl;

            if (attempt != target)
            {
                if (badchars.length() > 0)
                {
                    std::cout << "Niepoprawne litery: " << badchars << std::endl;
                    std::cout << "Możesz pomylić się jeszcze " << guesses << " razy.\n";
                }
            }
        }
            if (guesses > 0)
            {
                std::cout << "To już całe słowo! \n";
            }
            else
            {
                std::cout << "Niestety, to słowo to: " << target << ".\n";
            }

            std::cout << "Czy chcesz zagrać jeszcze raz? <t/n> ";
            std::cin >> play;
            play = tolower(play);
        }
    std::cout << "Koniec.\n";
}

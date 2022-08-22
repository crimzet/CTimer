#include <iostream>
#include <chrono>

int s = 0, m = 0, w = 4, h = 5, elapsed = 0;
char Numbers[10][5][7] = {
    {
        "######",
        "##  ##",
        "##  ##",
        "##  ##",
        "######"
    },
    {
        "####  ",
        "  ##  ",
        "  ##  ",
        "  ##  ",
        "######"
    },
    {
        "######",
        "    ##",
        "######",
        "##    ",
        "######"
    },
    {
        "######",
        "    ##",
        "######",
        "    ##",
        "######"
    },
    {
        "##  ##",
        "##  ##",
        "######",
        "    ##",
        "    ##"
    },
    {
        "######",
        "##    ",
        "######",
        "    ##",
        "######"
    },
    {
        "######",
        "##    ",
        "######",
        "##  ##",
        "######"
    },
    {
        "######",
        "    ##",
        "    ##",
        "    ##",
        "    ##"
    },
    {
        "######",
        "##  ##",
        "######",
        "##  ##",
        "######"
    },
    {
        "######",
        "##  ##",
        "######",
        "    ##",
        "######"
    }
};
char Timer[10][63] = {
    "____________________________________________________________",
    "------------------------------------------------------------",
    "||                                                        ||",
    "||      ######   ######              ######   ######      ||",
    "||      ######   ######      **      ######   ######      ||",
    "||      ######   ######      **      ######   ######      ||",
    "||      ######   ######      **      ######   ######      ||",
    "||      ######   ######              ######   ######      ||",
    "||                                                        ||",
    "============================================================"
};
void SetSec(int num);
void SetMin(int num);
bool isNumber(char s[]);

int main(int argc, char** argv)
{
    // Check if called correctly
    if (argc < 2 && argc > 3 && isNumber(argv[1]))
    {
        std::cout << "Error: Incorrect usage.\n" << "Usage: ./timer [<minutes>] <seconds>\n" << "Example: ./timer 12 45\n";
        return 1;
    }

    s = std::stoi(argv[1]);
    if (argc == 3 && isNumber(argv[2]))
    {
        s = std::stoi(argv[2]);
        m = std::stoi(argv[1]);
    }
    
    // Check if seconds and minutes are less than 60
    if (s / 60 >= 1 || m / 60 >= 1)
    {
        std::cout << "Error: Wrong time format.\n";
        return 1;
    }

    auto t_s = std::chrono::high_resolution_clock::now();
    while (s != 0 || m != 0)
    {
        // Run every second
        if (elapsed == 1000)
        {
            // Decrease seconds and minutes if seconds = 0
            if (s == 0)
            {
                m--;
                s = 60;
            }
            s--;

            // Update console
            std::system("clear");

            SetSec(s);
            SetMin(m);

            // Draw timer
            for (int i = 0; i < 10; ++i)
            {
                std::cout << Timer[i] << std::endl;
            }
            t_s = std::chrono::high_resolution_clock::now();
        }
        elapsed = std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now() - t_s).count();
    }

    // Notify of the timer being finished
    std::cout << '\a';
    std::cout << '\a';
    std::cout << '\a';

    return 0;
}

void SetSec(int num)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            Timer[i + 3][j + 37] = Numbers[num / 10][i][j];
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            Timer[i + 3][j + 46] = Numbers[num % 10][i][j];
        }
    }
};
void SetMin(int num)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            Timer[i + 3][j + 8] = Numbers[num / 10][i][j];
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 6; ++j)
        {
            Timer[i + 3][j + 17] = Numbers[num % 10][i][j];
        }
    }
};
bool isNumber(char s[])
{
    char* p;
    std::strtol(s, &p, 10);
    return *p == 0;
};

#include "Game.h"
#include <windows.h>



int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double Range = 0.0;
    int number = 0;

    while (number != 2) {


        int Value = 0;
        int Reg = 0;



    start:



        std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
        std::cout << "1. Гонка для наземного транспорта " << std::endl;
        std::cout << "2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта" << std::endl;
        std::cout << "Выберите тип гонки : ";

        if (!(std::cin >> Value)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
            goto start;
        }

        if (Value < 1 || Value > 3) {
            std::cout << "Вы ввели неправильное значение" << std::endl;
            goto start;
        }
        system("cls");



    range:
        std::cout << "Укажите длину дистанции (должна быть положительна): ";

        if (!(std::cin >> Range)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
            goto range;
        }

        if (Range <= 0) {
            std::cout << "Длина должна быть положительна. Попробуйте снова." << std::endl;
            goto range;
        }
        system("cls");



    registration_menu:

        std::cout << "1. Зарегестрировать транспорт " << std::endl;
        std::cout << "Выберите действие: ";

        if (!(std::cin >> Reg)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
            goto registration_menu;
        }

        if (Reg != 1) {
            std::cout << "Вы ввели неправильное значение" << std::endl;
            goto registration_menu;
        }

        system("cls");


        if (Value == 1) {
            if (Reg == 1) {

                int Number_Raser = 99;
                const int Max_Rasers = 5;
                double Times[Max_Rasers];
                std::string Names[Max_Rasers];
                int Count = 0;
                int counter = 0;
                bool alreadyExists = false;
                const char* currentName = nullptr;

                while (Number_Raser != 0 && Count != Max_Rasers) {


                registration:

                    std::cout << "Гонка для наземного транспорта. Расстояние: " << Range << std::endl;
                    std::cout << "Для старта гонки выберите минимум 2 транспортных средства" << std::endl;
                    std::cout << "Зарегестрированные траспортные средства :";


                    for (int i = 0; i < Count; ++i) {
                        std::cout << Names[i];
                        counter++;
                        if (i != Count - 1) {
                            std::cout << ", ";
                        }
                    }


                    std::cout << std::endl;
                    std::cout << "1.Верблюд" << std::endl;
                    std::cout << "2.Верблюд-быстроход" << std::endl;
                    std::cout << "3.Кентавр" << std::endl;
                    std::cout << "4.Ботинки-вездеходы" << std::endl;
                    std::cout << "0.Закончить регистрацию" << std::endl;
                    std::cout << "Выберите наземные транспортные средства и нажмите 0 для окончания регистрации" << std::endl;




                    if (!(std::cin >> Number_Raser)) {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
                        goto registration;
                    }

                    if (Number_Raser != 1 && Number_Raser != 2 && Number_Raser != 3 && Number_Raser != 4 && Number_Raser != 0) {
                        std::cout << "Вы ввели неправильное значение" << std::endl;
                        goto registration;
                    }


                    system("cls");


                    bool alreadyExists = false;
                    std::string currentName = " ";

                    if (Number_Raser == 1) {
                        currentName = "Верблюд";
                    }
                    else if (Number_Raser == 2) {
                        currentName = "Верблюд-быстроход";
                    }
                    else if (Number_Raser == 3) {
                        currentName = "Кентавр";
                    }
                    else if (Number_Raser == 4) {
                        currentName = "Ботинки-вездеходы";
                    }

                    for (int i = 0; i < Count; i++) {

                        if (Names[i] == currentName) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    if (alreadyExists == false) {

                        std::cout << currentName << " уcпешно зарегистрирован!" << std::endl;
                    }
                    if (alreadyExists == true) {
                        std::cout << currentName << " уже зарегистрирован! Выберите другого." << std::endl;
                        goto registration;
                    }


                    if (Number_Raser == 1) {
                        Camel camel;
                        Times[Count] = camel.Result_Math_Camel(Range);
                        Names[Count] = "Верблюд";
                        Count++;
                    }
                    else if (Number_Raser == 2) {
                        Camel_Faster camel_faster;
                        Times[Count] = camel_faster.Result_Math_Camel_Faster(Range);
                        Names[Count] = "Верблюд-быстроход";
                        Count++;
                    }
                    else if (Number_Raser == 3) {
                        Centaur centaur;
                        Times[Count] = centaur.Result_Math_Centaur(Range);
                        Names[Count] = "Кентавр";
                        Count++;
                    }
                    else if (Number_Raser == 4) {
                        Boots boots;
                        Times[Count] = boots.Result_Math_Boots(Range);
                        Names[Count] = "Ботинки-вездеходы";
                        Count++;
                    }

                    if (Number_Raser == 0 && counter == 1)
                    {
                        std::cout << "Недостаточно участников для гонки " << std::endl;
                        std::cout << "Выберите ещё одного участника гонки " << std::endl;
                        counter = 1;
                        goto  registration;

                    }

                    if (Number_Raser == 0 && counter == 0) {
                        std::cout << "Недостаточно участников для гонки " << std::endl;
                        std::cout << "Для старта гонки выберите минимум 2 транспортных средства" << std::endl;
                        counter = 0;
                        goto  registration;
                    };

                    if (Count == Max_Rasers - 1) {
                        Number_Raser = 0;
                    };

                    if (Number_Raser == 0 && Count > 1) {

                        system("cls");
                        for (int i = 0; i < Count - 1; i++) {
                            for (int j = 0; j < Count - i - 1; j++) {
                                if (Times[j] > Times[j + 1]) {
                                    std::swap(Times[j], Times[j + 1]);
                                    std::swap(Names[j], Names[j + 1]);
                                };
                            }
                        };
                        std::cout << "Результат гонки" << std::endl;
                        std::cout << std::endl;
                        for (int i = 0; i < Count; i++) {
                            std::cout << (i + 1) << ". " << Names[i] << ". Время : " << Times[i] << std::endl;
                        };
                    };
                };
            };

        };

        if (Value == 2) {
            if (Reg == 1) {

                int Number_Raser = 99;
                const int Max_Rasers = 4;
                double Times[Max_Rasers];
                std::string Names[Max_Rasers];
                int Count = 0;
                int counter = 0;
                bool alreadyExists = false;
                const char* currentName = nullptr;

                while (Number_Raser != 0 && Count != Max_Rasers) {


                registration_2:

                    std::cout << "Гонка для воздушного транспорта. Расстояние: " << Range << std::endl;
                    std::cout << "Для старта гонки выберите минимум 2 транспортных средства" << std::endl;
                    std::cout << "Зарегестрированные траспортные средства :";


                    for (int i = 0; i < Count; ++i) {
                        std::cout << Names[i];
                        counter++;
                        if (i != Count - 1) {
                            std::cout << ", ";
                        }
                    }


                    std::cout << std::endl;
                    std::cout << "1.Ковёр-самолёт" << std::endl;
                    std::cout << "2.Орёл" << std::endl;
                    std::cout << "3.Метла" << std::endl;
                    std::cout << "0.Закончить регистрацию" << std::endl;
                    std::cout << "Выберите наземные транспортные средства и нажмите 0 для окончания регистрации" << std::endl;




                    if (!(std::cin >> Number_Raser)) {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
                        goto registration_2;
                    }

                    if (Number_Raser != 1 && Number_Raser != 2 && Number_Raser != 3 && Number_Raser != 0) {
                        std::cout << "Вы ввели неправильное значение" << std::endl;
                        goto registration_2;
                    }


                    system("cls");


                    bool alreadyExists = false;
                    std::string currentName = " ";

                    if (Number_Raser == 1) {
                        currentName = "Ковёр-самолёт";
                    }
                    else if (Number_Raser == 2) {
                        currentName = "Орёл";
                    }
                    else if (Number_Raser == 3) {
                        currentName = "Метла";
                    }

                    for (int i = 0; i < Count; i++) {

                        if (Names[i] == currentName) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    if (alreadyExists == false) {

                        std::cout << currentName << " уcпешно зарегистрирован!" << std::endl;
                    }
                    if (alreadyExists == true) {
                        std::cout << currentName << " уже зарегистрирован! Выберите другого." << std::endl;
                        goto registration_2;
                    }


                    if (Number_Raser == 1) {
                        Magic_Carpet magic_carper;
                        Times[Count] = magic_carper.Result_Math_Magic_Carpet(Range);
                        Names[Count] = "Ковёр-самолёт";
                        Count++;
                    }
                    else if (Number_Raser == 2) {
                        Eagle eagle;
                        Times[Count] = eagle.Result_Math_Eagle(Range);
                        Names[Count] = "Орёл";
                        Count++;
                    }
                    else if (Number_Raser == 3) {
                        Broomstick broomstick;
                        Times[Count] = broomstick.Result_Math_Broomstick(Range);
                        Names[Count] = "Метла";
                        Count++;
                    }


                    if (Number_Raser == 0 && counter == 1)
                    {
                        std::cout << "Недостаточно участников для гонки " << std::endl;
                        std::cout << "Выберите ещё одного участника гонки " << std::endl;
                        counter = 1;
                        goto  registration_2;

                    }

                    if (Number_Raser == 0 && counter == 0) {
                        std::cout << "Недостаточно участников для гонки " << std::endl;
                        std::cout << "Для старта гонки выберите минимум 2 транспортных средства" << std::endl;
                        counter = 0;
                        goto  registration_2;
                    };

                    if (Count == Max_Rasers - 1) {
                        Number_Raser = 0;
                    };

                    if (Number_Raser == 0 && Count > 1) {

                        system("cls");
                        for (int i = 0; i < Count - 1; i++) {
                            for (int j = 0; j < Count - i - 1; j++) {
                                if (Times[j] > Times[j + 1]) {
                                    std::swap(Times[j], Times[j + 1]);
                                    std::swap(Names[j], Names[j + 1]);
                                };
                            }
                        };
                        std::cout << "Результат гонки" << std::endl;
                        std::cout << std::endl;
                        for (int i = 0; i < Count; i++) {
                            std::cout << (i + 1) << ". " << Names[i] << ". Время : " << Times[i] << std::endl;
                        };
                    };
                };
            };
        };
        if (Value == 3) {
            if (Reg == 1) {

                int Number_Raser = 99;
                const int Max_Rasers = 8;
                double Times[Max_Rasers];
                std::string Names[Max_Rasers];
                int Count = 0;
                int counter = 0;
                bool alreadyExists = false;
                const char* currentName = nullptr;

                while (Number_Raser != 0 && Count != Max_Rasers) {


                registration_3:

                    std::cout << "Гонка для воздушного транспорта. Расстояние: " << Range << std::endl;
                    std::cout << "Для старта гонки выберите минимум 2 транспортных средства" << std::endl;
                    std::cout << "Зарегестрированные траспортные средства :";


                    for (int i = 0; i < Count; ++i) {
                        std::cout << Names[i];
                        counter++;
                        if (i != Count - 1) {
                            std::cout << ", ";
                        }
                    }


                    std::cout << std::endl;
                    std::cout << "1.Ботинки-вездеходы" << std::endl;
                    std::cout << "2.Метла" << std::endl;
                    std::cout << "3.Верблюд" << std::endl;
                    std::cout << "4.Кентавр" << std::endl;
                    std::cout << "5.Орёл" << std::endl;
                    std::cout << "6.Верблюд-быстроход" << std::endl;
                    std::cout << "7.Ковёр-самолёт" << std::endl;
                    std::cout << "0.Закончить регистрацию" << std::endl;
                    std::cout << "Выберите наземные транспортные средства и нажмите 0 для окончания регистрации" << std::endl;




                    if (!(std::cin >> Number_Raser)) {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
                        goto registration_3;
                    }

                    if (Number_Raser != 1 && Number_Raser != 2 && Number_Raser != 3 && Number_Raser != 4 && Number_Raser != 5 && Number_Raser != 6 && Number_Raser != 7 && Number_Raser != 0) {
                        std::cout << "Вы ввели неправильное значение" << std::endl;
                        goto registration_3;
                    }


                    system("cls");


                    bool alreadyExists = false;
                    std::string currentName = " ";

                    if (Number_Raser == 1) {
                        currentName = "Ботинки-вездеходы";
                    }
                    else if (Number_Raser == 2) {
                        currentName = "Метла";
                    }
                    else if (Number_Raser == 3) {
                        currentName = "Верблюд";
                    }
                    else if (Number_Raser == 4) {
                        currentName = "Кентавр";
                    }
                    else if (Number_Raser == 5) {
                        currentName = "Орёл";
                    }
                    else if (Number_Raser == 6) {
                        currentName = "Верблюд-быстроход";
                    }
                    else if (Number_Raser == 7) {
                        currentName = "Ковёр-самолёт";
                    }


                    for (int i = 0; i < Count; i++) {

                        if (Names[i] == currentName) {
                            alreadyExists = true;
                            break;
                        }
                    }
                    if (alreadyExists == false) {

                        std::cout << currentName << " уcпешно зарегистрирован!" << std::endl;
                    }
                    if (alreadyExists == true) {
                        std::cout << currentName << " уже зарегистрирован! Выберите другого." << std::endl;
                        goto registration_3;
                    }


                    if (Number_Raser == 1) {
                        Boots boots;
                        Times[Count] = boots.Result_Math_Boots(Range);
                        Names[Count] = "Ботинки-вездеходы";
                        Count++;
                    }
                    else if (Number_Raser == 2) {
                        Broomstick broomstick;
                        Times[Count] = broomstick.Result_Math_Broomstick(Range);
                        Names[Count] = "Метла";
                        Count++;
                    }
                    else if (Number_Raser == 3) {
                        Camel camel;
                        Times[Count] = camel.Result_Math_Camel(Range);
                        Names[Count] = "Верблюд";
                        Count++;
                    }
                    else if (Number_Raser == 4) {
                        Centaur centaur;
                        Times[Count] = centaur.Result_Math_Centaur(Range);
                        Names[Count] = "Кентавр";
                        Count++;
                    }
                    else if (Number_Raser == 5) {
                        Eagle eagle;
                        Times[Count] = eagle.Result_Math_Eagle(Range);
                        Names[Count] = "Орёл";
                        Count++;
                    }
                    else if (Number_Raser == 6) {
                        Camel_Faster camel_faster;
                        Times[Count] = camel_faster.Result_Math_Camel_Faster(Range);
                        Names[Count] = "Верблюд-быстроход";
                        Count++;
                    }
                    else if (Number_Raser == 7) {
                        Magic_Carpet magic_carpet;
                        Times[Count] = magic_carpet.Result_Math_Magic_Carpet(Range);
                        Names[Count] = "Ковёр-самолёт";
                        Count++;
                    }


                    if (Number_Raser == 0 && counter == 1)
                    {
                        std::cout << "Недостаточно участников для гонки " << std::endl;
                        std::cout << "Выберите ещё одного участника гонки " << std::endl;
                        counter = 1;
                        goto  registration_3;

                    }

                    if (Number_Raser == 0 && counter == 0) {
                        std::cout << "Недостаточно участников для гонки " << std::endl;
                        std::cout << "Для старта гонки выберите минимум 2 транспортных средства" << std::endl;
                        counter = 0;
                        goto  registration_3;
                    };

                    if (Count == Max_Rasers - 1) {
                        Number_Raser = 0;
                    };

                    if (Number_Raser == 0 && Count > 1) {

                        system("cls");
                        for (int i = 0; i < Count - 1; i++) {
                            for (int j = 0; j < Count - i - 1; j++) {
                                if (Times[j] > Times[j + 1]) {
                                    std::swap(Times[j], Times[j + 1]);
                                    std::swap(Names[j], Names[j + 1]);
                                };
                            }
                        };
                        std::cout << "Результат гонки" << std::endl;
                        std::cout << std::endl;
                        for (int i = 0; i < Count; i++) {
                            std::cout << (i + 1) << ". " << Names[i] << ". Время : " << Times[i] << std::endl;
                        };
                    };
                };
            };
        };


    restart:
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "1.Провести ещё одну гонку " << std::endl;
        std::cout << "2.Выйти" << std::endl;
        std::cout << "Введите значение :";

        if (!(std::cin >> number)) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Вы ввели недопустимый символ. Попробуйте снова." << std::endl;
            goto restart;
        }

        if (number != 1 && number != 2) {
            std::cout << "Вы ввели неправильное значение" << std::endl;
            goto restart;
        }
        if (number == 1) {
            system("cls");
            goto start;
        }
    };
    return 0;
};
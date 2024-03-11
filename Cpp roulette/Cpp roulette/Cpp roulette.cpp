#include <Windows.h>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
int ammo[5];
string wy;
string st;
int i = 0;
int lupa;
int piwko;
int noz;
int kajdanki;
int phealth = 5;
int ehealth = 5;
int pdamage = 1;
int edamage = 1;
int runda = 1;
int ik = 0;
int eci = 0;
int eitems[3];
int ek = 0;
int nu = 0;
int ku = 0;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	cout << "Witaj w Cpp roulette!\n";
	cout << " " << endl;
	cout << "Jezeli chcesz wiedziec jak grac uzyj polecenia: >HELP\n";
	cout << " " << endl;
	cout << "Aby rozpoczac gre wpisz: >GRAJ\n";
	cout << " " << endl;

	wybor:
	cin >> wy;

	if (wy == ">HELP")
	{
		SetConsoleTextAttribute(h, 15);
		cout << "---- POMOC ----\n";
		cout << ">Lupa - Sprawdzasz jaki naboj jest naladowany\n";
		cout << ">Piwko - Pomijasz strzelanie i pijesz piwo\n";
		cout << ">Noz - Przycinasz lufe od strzelby i wtedy zadaje 2x wiecej obrazen\n";
		cout << ">Sja - Strzelasz w siebie\n";
		cout << ">Sprz - Strzelasz w przeciwnika\n";
		cout << ">Kajdanki - Mozesz 2 razy strzelic\n";
		SetConsoleTextAttribute(h, 7);
	}
	if (wy == ">GRAJ")
	{
		SetConsoleTextAttribute(h, 1);
		cout << " " << endl;
		cout << "Rozpoczynanie gry...\n";
		cout << " " << endl;
		cout << " " << endl;

		cout << "Runda pierwsza rozpoczeta!\n";

		losowanieammo:

			if (runda == 3)
			{
				SetConsoleTextAttribute(h, 1);
				cout << "Finalowa runda! walcz na smierc i zycie!\n";
			}

			i = 0;
			cout << " " << endl;
			cout << " " << endl;
			cout << " " << endl;
			cout << "Losowanie magazynka!\n ";
			SetConsoleTextAttribute(h, 7);
			cout << " " << endl;
			cout << " " << endl;
			Sleep(3000);

			srand(time(NULL));

			ammo[0] = rand() % 2;
			ammo[1] = rand() % 2;
			ammo[2] = rand() % 2;
			ammo[3] = rand() % 2;
			ammo[4] = rand() % 2;

			int Tb = 0;
			int Fb = 0;

			if (ammo[0] == 1)
			{
				Tb++;
			}
			else
			{
				Fb++;
			}
			if (ammo[1] == 1)
			{
				Tb++;
			}
			else
			{
				Fb++;
			}
			if (ammo[2] == 1)
			{
				Tb++;
			}
			else
			{
				Fb++;
			}
			if (ammo[3] == 1)
			{
				Tb++;
			}
			else
			{
				Fb++;
			}
			if (ammo[4] == 1)
			{
				Tb++;
			}
			else
			{
				Fb++;
			}

			lupa = lupa + rand() % 2;
			piwko = piwko + rand() % 2;
			noz = noz + rand() % 2;
			kajdanki = kajdanki + rand() % 2;
			
			eitems[0] = eitems[0] + rand() % 2;
			eitems[1] = eitems[1] + rand() % 2;
			eitems[2] = eitems[2] + rand() % 2;

			ku = 0;
			ek = 0;
			ik = 0;
			SetConsoleTextAttribute(h, 1);
			cout << "Jest " << Tb << " prawdziwych naboji i " << Fb << " falszywych naboji." << endl;
			Sleep(2000);
			cout << " " << endl;
			cout << "Masz " << lupa << " lupe, " << piwko << " piwko, " << noz << " noz i " << kajdanki << " kajdanki." << endl;
			Sleep(2000);
			cout << " " << endl;
			cout << "Przeciwnik ma " << eitems[0] << " piwko, " << eitems[1] << " noz i " << eitems[2] << " kajdanki " << endl;
			Sleep(2000);
			cout << " " << endl;
			SetConsoleTextAttribute(h, 7);

		int start = rand() % 2;

		if (start == 1)
		{
			SetConsoleTextAttribute(h, 10);
			cout << "Zaczynasz gre!\n";
			cout << " " << endl;
			SetConsoleTextAttribute(h, 7);

			turagracza:

				if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }

				cin >> st;

				if (st == ">Sja")
				{
					cout << " " << endl;
					cout << "Strzelasz w przeciwnika\n";
					cout << " " << endl;
					Sleep(3000);


					if (ammo[i] == 1)
					{
						SetConsoleTextAttribute(h, 10);
						cout << "Przeciwnik oberwal! Traci zycie!\n";
						cout << " " << endl;
						ehealth = ehealth - pdamage;
						pdamage = 1;
						cout << "Zostalo mu " << ehealth << " zyc\n";
						SetConsoleTextAttribute(h, 7);
						if (ehealth <= 0)
						{
							if (runda == 3)
							{
								SetConsoleTextAttribute(h, 10);
								cout << " " << endl;
								cout << "Udalo ci sie! Wygrywasz gre i nagrode w postaci dodatkowego ramu!\n";
								SetConsoleTextAttribute(h, 7);
								Sleep(2000);
								goto koniecgry;
							}
							else
							{
								SetConsoleTextAttribute(h, 10);
								cout << " " << endl;
								runda++;
								cout << " Przeciwnik polegl!. Runda: " << runda << endl;
								SetConsoleTextAttribute(h, 7);
								phealth = 5;
								ehealth = 5;
								Sleep(3000);
								goto losowanieammo;
							}

						}
						Sleep(3000);

						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }

						i++;
						if (ik == 1)
						{
							ik = 0;
							goto turagracza;
						}
						else
						{
							goto turaprzeciwnika;
						}

					}
					else
					{
						cout << " " << endl;
						SetConsoleTextAttribute(h, 8);
						cout << "Pocisk byl pusty!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						pdamage = 1;
						Sleep(3000);

						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }


						i++;
						if (ik == 1)
						{
							ik = 0;
							goto turagracza;
						}
						else
						{
							goto turaprzeciwnika;
						}
					}
				}
				if (st == ">Sprz")
				{
					cout << " " << endl;
					cout << "Strzelasz w siebie\n";
					cout << " " << endl;
					Sleep(3000);

					if (ammo[i] == 1)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Pocisk byl prawdziwy! Tracisz zycie\n";
						cout << " " << endl;
						phealth = phealth - pdamage;
						pdamage = 1;
						cout << "Zostalo ci " << phealth << " zyc\n";
						cout << " " << endl;
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						if (phealth <= 0)
						{
							if (runda == 3)
							{
								SetConsoleTextAttribute(h, 4);
								cout << " " << endl;
								cout << "Przegrywasz... przeciwnik dostaje darmowy ram a ty zostajesz...\n";
								SetConsoleTextAttribute(h, 7);
								Sleep(2000);
								goto koniecgry;
							}
							else
							{
								SetConsoleTextAttribute(h, 4);
								cout << "" << endl;
								runda++;
								cout << " Przegrales! Runda: " << runda << endl;
								SetConsoleTextAttribute(h, 7);
								phealth = 5;
								ehealth = 5;
								Sleep(3000);
								goto losowanieammo;
							}
						}
						else
						{
							Sleep(3000);

							if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }

							i++;

							if (ik == 1)
							{
								ik = 0;
								goto turagracza;
							}
							else
							{
								goto turaprzeciwnika;
							}

							goto turaprzeciwnika;
						}

					}
					else
					{
						SetConsoleTextAttribute(h, 10);
						cout << " " << endl;
						cout << "Pocisk byl pusty! Miales farta.\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						Sleep(3000);

						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }
						else
						{
							SetConsoleTextAttribute(h, 1);
							cout << "Dostajesz dodatkowa ture!\n";
							SetConsoleTextAttribute(h, 7);

							i++;
							goto turagracza;
						}

					}
				}
				if (st == ">Lupa")
				{
					if (lupa > 0)
					{
						if (ammo[i] == 1)
						{
							cout << " " << endl;
							cout << "Teraz naladowany jest prawdziwy naboj!\n";
							cout << " " << endl;
						}
						else
						{
							cout << " " << endl;
							cout << "Naboj jest pusty!\n";
							cout << " " << endl;
						}
						goto turagracza;
					}
					else
					{
						SetConsoleTextAttribute(h, 8);
						cout << " " << endl;
						cout << "Nie masz tego przedmiotu!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;

						goto turagracza;
					}

				}
				if (st == ">Piwko")
				{
					if (piwko > 0)
					{
						cout << " " << endl;
						cout << "Pomijasz strzelanie i wyrzucasz aktualny naboj!\n";
						cout << " " << endl;
						i++;
						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }
						else
						{
							if (ik == 1)
							{
								Sleep(2000);
								goto turagracza;
							}
							else
							{
								Sleep(2000);
								goto turaprzeciwnika;
							}

						}

					}
					else
					{
						SetConsoleTextAttribute(h, 8);
						cout << " " << endl;
						cout << "Nie masz tego przedmiotu!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;

						goto turagracza;
					}

				}
				if (st == ">Noz")
				{
					if (noz > 0)
					{
						cout << " " << endl;
						cout << "Odkrajasz lufe i teraz obrazenia od pociska sa 2x wieksze!\n";
						cout << " " << endl;
						pdamage = 2;
						goto turagracza;
					}
					else
					{
						SetConsoleTextAttribute(h, 8);
						cout << " " << endl;
						cout << "Nie masz tego przedmiotu!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;

						goto turagracza;
					}

				}
				if (st == ">Kajdanki")
				{
					if (kajdanki > 0)
					{
						cout << " " << endl;
						cout << "Masz dodatkowa ture\n";
						cout << " " << endl;
						ik = 1;
						goto turagracza;
					}
					else
					{
						SetConsoleTextAttribute(h, 8);
						cout << " " << endl;
						cout << "Nie masz tego przedmiotu!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;

						goto turagracza;
					}

				}
				else
				{
					SetConsoleTextAttribute(h, 4);
					cout << " " << endl;
					cout << "Nieprawidlowe polecenie\n";
					SetConsoleTextAttribute(h, 7);
					cout << " " << endl;
					goto turagracza;

				}


			turaprzeciwnika:

				if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }

				int wsg = rand() % 5;
				if (wsg == 1)
				{
					cout << "Przeciwnik strzela w ciebie!\n";
					cout << " " << endl;
					Sleep(3000);

					if (ammo[i] == 1)
					{
						SetConsoleTextAttribute(h, 4);
						cout << "Pocisk byl prawdziwy! Tracisz zycie\n";
						cout << " " << endl;
						phealth = phealth - edamage;
						cout << "Zostalo ci " << phealth << " zyc\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						edamage = 1;
						nu = 0;
						if (phealth <= 0)
						{
							if (runda == 3)
							{
								SetConsoleTextAttribute(h, 4);
								cout << " " << endl;
								cout << "Przegrywasz... przeciwnik dostaje darmowy ram a ty zostajesz...\n";
								SetConsoleTextAttribute(h, 7);
								cout << " " << endl;
								Sleep(2000);
								goto koniecgry;
							}
							else
							{
								SetConsoleTextAttribute(h, 4);
								cout << " " << endl;
								runda++;
								cout << " Przegrales! Runda: " << runda << endl;
								SetConsoleTextAttribute(h, 7);
								cout << " " << endl;
								phealth = 5;
								ehealth = 5;
								Sleep(3000);
								goto losowanieammo;
							}
						}
						Sleep(3000);

						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }


						i++;
						if (ek == 1)
						{
							ek = 0;
							ku = 0;
							goto turaprzeciwnika;
						}
						else
						{
							goto turagracza;
						}

					}
					else
					{
						SetConsoleTextAttribute(h, 10);
						cout << " " << endl;
						cout << "Pocisk byl pusty!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						Sleep(3000);

						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }


						i++;
						if (ek == 1)
						{
							ek = 0;
							ku = 0;
							goto turaprzeciwnika;
						}
						else
						{
							goto turagracza;
						}
					}
				}

				if (wsg == 0)
				{
					cout << " " << endl;
					cout << "Przeciwnik strzela w siebie! Co za odwazny typ!\n";
					cout << " " << endl;
					Sleep(3000);

					if (ammo[i] == 1)
					{
						SetConsoleTextAttribute(h, 10);
						cout << "Ha! Przeciwnik oberwal! Traci zycie!\n";
						cout << " " << endl;
						ehealth = ehealth - edamage;
						cout << "Zostalo mu " << ehealth << " zyc\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						edamage = 1;
						nu = 0;
						cout << " " << endl;
						if (ehealth <= 0)
						{
							if (runda == 3)
							{
								SetConsoleTextAttribute(h, 10);
								cout << " " << endl;
								cout << "Udalo ci sie! Wygrywasz gre i nagrode w postaci dodatkowego ramu!\n";
								SetConsoleTextAttribute(h, 7);
								cout << " " << endl;
								Sleep(2000);
								goto koniecgry;
							}
							else
							{
								SetConsoleTextAttribute(h, 10);
								cout << "" << endl;
								runda++;
								cout << " Przeciwnik polegl!. Runda: " << runda << endl;
								SetConsoleTextAttribute(h, 7);
								cout << " " << endl;
								phealth = 5;
								ehealth = 5;
								Sleep(3000);
								goto losowanieammo;
							}
						}
						else
						{
							Sleep(3000);

							if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }


							i++;
							if (ek == 1)
							{
								ek = 0;
								ku = 0;
								goto turaprzeciwnika;
							}
							else
							{
								goto turagracza;
							}
						}

					}
					else
					{
						SetConsoleTextAttribute(h, 8);
						cout << " " << endl;
						cout << "Kurde co za fart, pocisk byl pusty!\n";
						SetConsoleTextAttribute(h, 7);
						cout << " " << endl;
						Sleep(3000);

						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }
						else
						{
							cout << "Przeciwnik dostaje dodatkowa ture!\n";

							i++;
							goto turaprzeciwnika;
						}

						if (ek == 1)
						{
							ek = 0;
							ku = 0;
							goto turaprzeciwnika;
						}
						else
						{
							goto turagracza;
						}
					}
				}
				if (wsg == 2)
				{
					if (eitems[0] > 0)
					{
						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }
						cout << " " << endl;
						cout << "Przeciwnik pomija strzelanie i wyrzuca naboj.\n";
						cout << " " << endl;
						i++;
						if (sizeof(ammo) / sizeof(ammo[0]) == i) { i = 0; cout << " " << endl; SetConsoleTextAttribute(h, 1); cout << "Koniec magazynka! Losowanie nowego.\n"; SetConsoleTextAttribute(h, 7); goto losowanieammo; }
						else
						{
							if (ku == 1)
							{
								ku = 0;
								ek = 0;
								Sleep(2000);
								goto turaprzeciwnika;
							}
							else
							{
								Sleep(2000);
								goto turagracza;
							}
						}

					}
					else
					{
						goto turaprzeciwnika;
					}
				}
				if (wsg == 3)
				{
					if (nu == 0)
					{
						if (eitems[1] > 0)
						{
							cout << " " << endl;
							cout << "Przeciwnik uzywa noza i lufa zadaje 2x damage!\n";
							cout << " " << endl;
							edamage = 2;
							nu = 1;
							Sleep(1000);
							goto turaprzeciwnika;
						}
						else
						{
							goto turaprzeciwnika;
						}
					}
					else
					{
						goto turaprzeciwnika;
					}

				}
				if (wsg == 4)
				{
					if (ku == 0)
					{
						if (eitems[1] > 0)
						{
							cout << " " << endl;
							cout << "Przeciwnik uzywa kajdanek i ma 2 tury!\n";
							cout << " " << endl;
							ek = 1;
							ku = 1;
							Sleep(1000);
							goto turaprzeciwnika;
						}
						else
						{
							goto turaprzeciwnika;
						}
					}
					else
					{
						goto turaprzeciwnika;
					}

				}
		}
		else
		{
			cout << " " << endl;
			SetConsoleTextAttribute(h, 4);
			cout << "Przeciwnik zaczyna!\n";
			SetConsoleTextAttribute(h, 7);
			cout << " " << endl;
			Sleep(3000);
			goto turaprzeciwnika;
		}



	}
	else
	{
		cout << " " << endl;
		SetConsoleTextAttribute(h, 4);
		cout << "Bledne polecenie\n";
		SetConsoleTextAttribute(h, 7);
		cout << " " << endl;
		goto wybor;
	}

	koniecgry:
		if ( phealth <= 0 )
		{
			SetConsoleTextAttribute(h, 4);
			cout << "WYLACZONY\n";
			Sleep(1000);
			system("shutdown -s");
			exit(0);

		}
		else
		{
			SetConsoleTextAttribute(h, 4);
			cout << "Za chwile nastapi wylaczenie gry\n";
			Sleep(3000);
			exit(0);
		}
}

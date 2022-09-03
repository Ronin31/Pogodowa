#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <windows.h>
#include <winbase.h>


#define MAX_LICZBA_POZIOMOW 3
class napis

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite napis;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getNapis() { return napis; }
	sf::Vector2f getPozycja() {
		return napis.getPosition();
	}

};

void napis::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Tlo.jpg");
	napis.setTexture(tekstura);
	napis.setPosition(position);
}

class Deszcz

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Deszcz;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getDeszcz() { return Deszcz; }
	sf::Vector2f getPozycja() {
		return Deszcz.getPosition();
	}

};

void Deszcz::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Deszcz.png");
	Deszcz.setTexture(tekstura);
	Deszcz.setPosition(position);
}

class Wiatr

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Wiatr;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getWiatr() { return Wiatr; }
	sf::Vector2f getPozycja() {
		return Wiatr.getPosition();
	}



};

void Wiatr::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Wiatr.png");
	Wiatr.setTexture(tekstura);
	Wiatr.setPosition(position);
}


class Ostrzezenie

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Ostrzezenie;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getOstrzezenie() { return Ostrzezenie; }
	sf::Vector2f getPozycja() {
		return Ostrzezenie.getPosition();
	}



};

void Ostrzezenie::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Ostrzezenie.png");
	Ostrzezenie.setTexture(tekstura);
	Ostrzezenie.setPosition(position);
}

class Tornado

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Tornado;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getTornado() { return Tornado; }
	sf::Vector2f getPozycja() {
		return Tornado.getPosition();
	}



};

void Tornado::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Tornado.png");
	Tornado.setTexture(tekstura);
	Tornado.setPosition(position);
}



class Wczyt

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Wczyt;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getWczyt() { return Wczyt; }
	sf::Vector2f getPozycja() {
		return Wczyt.getPosition();
	}



};

void Wczyt::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Tloz.jpg");
	Wczyt.setTexture(tekstura);
	Wczyt.setPosition(position);
}

class Start

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Start;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getStart() { return Start; }
	sf::Vector2f getPozycja() {
		return Start.getPosition();
	}



};

void Start::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Startowe.jpg");
	Start.setTexture(tekstura);
	Start.setPosition(position);
}


class Burza

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Burza;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getBurza() { return Burza; }
	sf::Vector2f getPozycja() {
		return Burza.getPosition();
	}



};

void Burza::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Burza.png");
	Burza.setTexture(tekstura);
	Burza.setPosition(position);
}


class Menu
{

private:
	sf::Font font;
	sf::Text menu[MAX_LICZBA_POZIOMOW];
	int selectedItem = 0;
	int Wybrany = 0;



public:
	Menu(float width, float height);
	~Menu() {};

	void moveUp();//przesun do gory
	void moveDown();//przesun w dol

	int getSelectedItem() { return selectedItem; }//zwroc poziom menu
	int getWybrany() { return Wybrany; }
	void draw(sf::RenderWindow& window);//rysuj menu w oknie


};






Menu::Menu(float width, float height)
{	//laduj czcionke
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString(L"Przewidywana pogoda");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString(L"Sugerowany ubiór");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString(L"Wygaś ekran");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_LICZBA_POZIOMOW + 1) * 3));

}



//rysowanie menu w biezacym oknie
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_LICZBA_POZIOMOW; i++)
	{
		window.draw(menu[i]);
	}

}






void Menu::moveUp()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem--;
		if (selectedItem < 0)
			selectedItem = MAX_LICZBA_POZIOMOW - 1;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}


}


void Menu::moveDown()
{
	if (selectedItem >= 0 && selectedItem < MAX_LICZBA_POZIOMOW)
	{
		menu[selectedItem].setFillColor(sf::Color::White);
		menu[selectedItem].setStyle(sf::Text::Regular);
		selectedItem++;
		if (selectedItem >= MAX_LICZBA_POZIOMOW)
			selectedItem = 0;
		menu[selectedItem].setFillColor(sf::Color::Cyan);
		menu[selectedItem].setStyle(sf::Text::Bold);
	}

}

void myDelay(int opoznienie)
{
	sf::Clock zegar;
	sf::Time czas;
	while (1)
	{
		czas = zegar.getElapsedTime();
		if (czas.asMilliseconds() > opoznienie)
		{
			zegar.restart();
			break;
		}

	}
}


class Opis_gry
{

private:
	sf::Font font;
	sf::Text Opis[65], poziomy[4], Koniec, Czy, Haz[4];
	sf::Vector2f position;

public:

	Opis_gry();
	void rysuj(sf::RenderWindow& window, int ktory);
};


Opis_gry::Opis_gry()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}
	Opis[0].setFont(font);
	Opis[0].setFillColor(sf::Color::Red);
	Opis[0].setCharacterSize(40);
	Opis[0].setPosition(350, 0);
	Opis[0].setString(L"Prognoza pogody na 3 godziny: ");

	Opis[1].setFont(font);
	Opis[1].setFillColor(sf::Color::Red);
	Opis[1].setCharacterSize(100);
	Opis[1].setPosition(450, 480);
	Opis[1].setString(L"Uwaga!");

	Opis[2].setFont(font);
	Opis[2].setFillColor(sf::Color::Black);
	Opis[2].setCharacterSize(40);
	Opis[2].setPosition(350, 60);
	Opis[2].setString(L"Silne podmuchy wiatru do 90 km/h");
	//Grad
	Opis[3].setFont(font);
	Opis[3].setFillColor(sf::Color::Black);
	Opis[3].setCharacterSize(40);
	Opis[3].setPosition(200, 600);
	Opis[3].setString(L"+ Możliwe opady gradu do 1 cm");

	Opis[4].setFont(font);
	Opis[4].setFillColor(sf::Color::Black);
	Opis[4].setCharacterSize(40);
	Opis[4].setPosition(200, 600);
	Opis[4].setString(L"+ Możliwe opady gradu do 3 cm");

	Opis[5].setFont(font);
	Opis[5].setFillColor(sf::Color::Black);
	Opis[5].setCharacterSize(40);
	Opis[5].setPosition(200, 600);
	Opis[5].setString(L"+ Możliwe opady gradu do 5 cm");

	Opis[6].setFont(font);
	Opis[6].setFillColor(sf::Color::Black);
	Opis[6].setCharacterSize(40);
	Opis[6].setPosition(200, 600);
	Opis[6].setString(L"+ Możliwe opady gradu powyżej 5 cm");

	Opis[7].setFont(font);
	Opis[7].setFillColor(sf::Color::Black);
	Opis[7].setCharacterSize(40);
	Opis[7].setPosition(200, 600);
	Opis[7].setString(L"+ Możliwy opad ekstremalnie dużego gradu powyżej 8 cm");
	
	// Wiatr
	Opis[8].setFont(font);
	Opis[8].setFillColor(sf::Color::Black);
	Opis[8].setCharacterSize(40);
	Opis[8].setPosition(10, 260);
	Opis[8].setString(L"+ Wiatr do 15 km/h");

	Opis[9].setFont(font);
	Opis[9].setFillColor(sf::Color::Black);
	Opis[9].setCharacterSize(40);
	Opis[9].setPosition(10, 260);
	Opis[9].setString(L"+ Wiatr do 30 km/h");

	Opis[10].setFont(font);
	Opis[10].setFillColor(sf::Color::Black);
	Opis[10].setCharacterSize(40);
	Opis[10].setPosition(10, 260);
	Opis[10].setString(L"+ Możliwe słabe podmuchy wiatru do 50 km/h");

	Opis[11].setFont(font);
	Opis[11].setFillColor(sf::Color::Black);
	Opis[11].setCharacterSize(40);
	Opis[11].setPosition(10, 260);
	Opis[11].setString(L"+ Możliwe podmuchy wiatru do 70 km/h");

	Opis[12].setFont(font);
	Opis[12].setFillColor(sf::Color::Black);
	Opis[12].setCharacterSize(40);
	Opis[12].setPosition(10, 260);
	Opis[12].setString(L"+ Możliwe silne podmuchy wiatru do 90 km/h");

	Opis[13].setFont(font);
	Opis[13].setFillColor(sf::Color::Black);
	Opis[13].setCharacterSize(40);
	Opis[13].setPosition(10, 260);
	Opis[13].setString(L"+ Możliwe bardzo silne podmuchy wiatru do 120 km/h");

	Opis[14].setFont(font);
	Opis[14].setFillColor(sf::Color::Black);
	Opis[14].setCharacterSize(40);
	Opis[14].setPosition(10, 260);
	Opis[14].setString(L"+ Możliwe ekstremalnie silne podmuchy wiatru przekraczające 120 km/h");
	//Deszcz
	Opis[15].setFont(font);
	Opis[15].setFillColor(sf::Color::Black);
	Opis[15].setCharacterSize(40);
	Opis[15].setPosition(10, 160);
	Opis[15].setString(L"+ Brak opadów deszczu");

	Opis[16].setFont(font);
	Opis[16].setFillColor(sf::Color::Black);
	Opis[16].setCharacterSize(40);
	Opis[16].setPosition(10, 160);
	Opis[16].setString(L"+ Możliwe wystąpienie przelotnych opadów deszczu");

	Opis[17].setFont(font);
	Opis[17].setFillColor(sf::Color::Black);
	Opis[17].setCharacterSize(40);
	Opis[17].setPosition(10, 160);
	Opis[17].setString(L"+ Umiarkowane opady deszczu");

	Opis[18].setFont(font);
	Opis[18].setFillColor(sf::Color::Black);
	Opis[18].setCharacterSize(40);
	Opis[18].setPosition(10, 160);
	Opis[18].setString(L"+ Możliwe wystąpienie silnych opadów deszczu");

	Opis[19].setFont(font);
	Opis[19].setFillColor(sf::Color::Black);
	Opis[19].setCharacterSize(40);
	Opis[19].setPosition(10, 160);
	Opis[19].setString(L"+ Ekstremalnie silne opady deszczu powodujące podtopienia");
	//Burze

	Opis[20].setFont(font);
	Opis[20].setFillColor(sf::Color::Black);
	Opis[20].setCharacterSize(40);
	Opis[20].setPosition(10, 60);
	Opis[20].setString(L"+ Nie przewiduje się wystąpienia burz");

	Opis[21].setFont(font);
	Opis[21].setFillColor(sf::Color::Black);
	Opis[21].setCharacterSize(40);
	Opis[21].setPosition(10, 60);
	Opis[21].setString(L"+ Możliwe słabe burze");

	Opis[22].setFont(font);
	Opis[22].setFillColor(sf::Color::Black);
	Opis[22].setCharacterSize(40);
	Opis[22].setPosition(10, 60);
	Opis[22].setString(L"+ Możliwe umiarkowanie silne burze");

	Opis[23].setFont(font);
	Opis[23].setFillColor(sf::Color::Black);
	Opis[23].setCharacterSize(40);
	Opis[23].setPosition(10, 60);
	Opis[23].setString(L"+ Duże ryzyko wystąpienia silnych burz");

	Opis[24].setFont(font);
	Opis[24].setFillColor(sf::Color::Black);
	Opis[24].setCharacterSize(40);
	Opis[24].setPosition(10, 60);
	Opis[24].setString(L"+ Ekstremalnie duże ryzyko wystąpienia bardzo silnych burz");

	// Trąba powietrzna
	Opis[25].setFont(font);
	Opis[25].setFillColor(sf::Color::Red);
	Opis[25].setCharacterSize(40);
	Opis[25].setPosition(200, 700);
	Opis[25].setString(L"+ Możliwe powstanie słabej trąby powietrznej");

	Opis[26].setFont(font);
	Opis[26].setFillColor(sf::Color::Red);
	Opis[26].setCharacterSize(40);
	Opis[26].setPosition(200, 700);
	Opis[26].setString(L"+ Możliwe powstanie trąby powietrznej o sile F1/F2");

	Opis[27].setFont(font);
	Opis[27].setFillColor(sf::Color::Red);
	Opis[27].setCharacterSize(40);
	Opis[27].setPosition(200, 700);
	Opis[27].setString(L"+ Duże ryzyko powstania silnej trąby powietrznej o sile F3");

	Opis[28].setFont(font);
	Opis[28].setFillColor(sf::Color::Red);
	Opis[28].setCharacterSize(40);
	Opis[28].setPosition(200, 700);
	Opis[28].setString(L"+ Duże ryzyko silnej trąby powietrznej o sile F4/F5!");

	//Nagłówki
	Opis[29].setFont(font);
	Opis[29].setFillColor(sf::Color::Black);
	Opis[29].setCharacterSize(50);
	Opis[29].setPosition(500, 110);
	Opis[29].setString(L"Deszcz");

	//Nagłówki
	Opis[30].setFont(font);
	Opis[30].setFillColor(sf::Color::Black);
	Opis[30].setCharacterSize(50);
	Opis[30].setPosition(500, 10);
	Opis[30].setString(L"Burze");
	//Grad
	Opis[31].setFont(font);
	Opis[31].setFillColor(sf::Color::Black);
	Opis[31].setCharacterSize(50);
	Opis[31].setPosition(500, 210);
	Opis[31].setString(L"Wiatr");
	//Mezocyklon
	Opis[32].setFont(font);
	Opis[32].setFillColor(sf::Color::Black);
	Opis[32].setCharacterSize(40);
	Opis[32].setPosition(200, 650);
	Opis[32].setString(L"+ Małe ryzyko powstania mezocyklonu ");

	Opis[33].setFont(font);
	Opis[33].setFillColor(sf::Color::Black);
	Opis[33].setCharacterSize(40);
	Opis[33].setPosition(200, 650);
	Opis[33].setString(L"+ Umiarkowane ryzyko powstania mezocyklonu ");

	Opis[34].setFont(font);
	Opis[34].setFillColor(sf::Color::Black);
	Opis[34].setCharacterSize(40);
	Opis[34].setPosition(200, 650);
	Opis[34].setString(L"+ Duże ryzyko powstania mezocyklonu ");
	//Ubiór
	Opis[35].setFont(font);
	Opis[35].setFillColor(sf::Color::Black);
	Opis[35].setCharacterSize(40);
	Opis[35].setPosition(10, 20);
	Opis[35].setString(L"+ Przewidywany jest upał. Najlepiej nie wychodź z domu. ");

	Opis[36].setFont(font);
	Opis[36].setFillColor(sf::Color::Black);
	Opis[36].setCharacterSize(40);
	Opis[36].setPosition(10, 70);
	Opis[36].setString(L"+ Pamiętaj o nawadnianiu się! ");

	Opis[37].setFont(font);
	Opis[37].setFillColor(sf::Color::Black);
	Opis[37].setCharacterSize(40);
	Opis[37].setPosition(10, 20);
	Opis[37].setString(L"+ Będzie słonecznie, bez opadów deszczu i silnych podmuchów wiatru. ");

	Opis[38].setFont(font);
	Opis[38].setFillColor(sf::Color::Black);
	Opis[38].setCharacterSize(40);
	Opis[38].setPosition(10, 70);
	Opis[38].setString(L"+ Polecany jest lekki i przewiewny strój. ");

	Opis[39].setFont(font);
	Opis[39].setFillColor(sf::Color::Black);
	Opis[39].setCharacterSize(40);
	Opis[39].setPosition(10, 20);
	Opis[39].setString(L"+ Będzie słonecznie, ale zimno. Nie przewiduje się opadów i silnego wiatru. ");
	
	Opis[40].setFont(font);
	Opis[40].setFillColor(sf::Color::Black);
	Opis[40].setCharacterSize(40);
	Opis[40].setPosition(10, 70);
	Opis[40].setString(L"+ Polecamy założyć bluzę i długie spodnie. ");

	Opis[41].setFont(font);
	Opis[41].setFillColor(sf::Color::Black);
	Opis[41].setCharacterSize(40);
	Opis[41].setPosition(10, 20);
	Opis[41].setString(L"+ Przewidywane są bardzo zimne temperatury przekraczające -15 stopni! ");

	Opis[42].setFont(font);
	Opis[42].setFillColor(sf::Color::Black);
	Opis[42].setCharacterSize(40);
	Opis[42].setPosition(10, 70);
	Opis[42].setString(L"+ Nie przebywaj zbyt długo na podwórku. Pamiętaj czapce, zimowej kurtce i rękawicach");

	Opis[43].setFont(font);
	Opis[43].setFillColor(sf::Color::Black);
	Opis[43].setCharacterSize(40);
	Opis[43].setPosition(10, 20);
	Opis[43].setString(L"+ Przewidywane są ujemne temperatury ");

	Opis[44].setFont(font);
	Opis[44].setFillColor(sf::Color::Black);
	Opis[44].setCharacterSize(40);
	Opis[44].setPosition(10, 70);
	Opis[44].setString(L"+ Ubierz się ciepło. Nie zapomnij o czapce i ciepłej kurtce");

	Opis[45].setFont(font);
	Opis[45].setFillColor(sf::Color::Black);
	Opis[45].setCharacterSize(40);
	Opis[45].setPosition(10, 20);
	Opis[45].setString(L"+ Przewiduje się, że będzie zimno, ale nie będzie mrozu");

	Opis[46].setFont(font);
	Opis[46].setFillColor(sf::Color::Black);
	Opis[46].setCharacterSize(40);
	Opis[46].setPosition(10, 70);
	Opis[46].setString(L"+ Ubierz się w kurtkę. Opcjonalnie polecamy założenie czapki");

	Opis[47].setFont(font);
	Opis[47].setFillColor(sf::Color::Black);
	Opis[47].setCharacterSize(40);
	Opis[47].setPosition(10, 20);
	Opis[47].setString(L"+ Przewidywane są przelotne opady deszczu");

	Opis[48].setFont(font);
	Opis[48].setFillColor(sf::Color::Black);
	Opis[48].setCharacterSize(40);
	Opis[48].setPosition(10, 70);
	Opis[48].setString(L"+ Weź ze sobą parasol albo płaszcz przeciwdeszczowy");

	Opis[49].setFont(font);
	Opis[49].setFillColor(sf::Color::Black);
	Opis[49].setCharacterSize(40);
	Opis[49].setPosition(10, 20);
	Opis[49].setString(L"+ Przewidywane są silne opady deszczu");

	Opis[50].setFont(font);
	Opis[50].setFillColor(sf::Color::Black);
	Opis[50].setCharacterSize(40);
	Opis[50].setPosition(10, 70);
	Opis[50].setString(L"+ Najlepiej zostać w domu. W przypadku wyjścia weź parasol");

	Opis[51].setFont(font);
	Opis[51].setFillColor(sf::Color::Black);
	Opis[51].setCharacterSize(40);
	Opis[51].setPosition(10, 20);
	Opis[51].setString(L"+ Przewidywany jest deszcz wraz z silniejszymi porywami wiatru");

	Opis[52].setFont(font);
	Opis[52].setFillColor(sf::Color::Black);
	Opis[52].setCharacterSize(40);
	Opis[52].setPosition(10, 70);
	Opis[52].setString(L"+ Weź ze sobą parasol i odzież, która chroni przed wiatrem ");

	Opis[53].setFont(font);
	Opis[53].setFillColor(sf::Color::Black);
	Opis[53].setCharacterSize(40);
	Opis[53].setPosition(10, 20);
	Opis[53].setString(L"+ Przewidywane są silne podmuchy wiatru");

	Opis[54].setFont(font);
	Opis[54].setFillColor(sf::Color::Black);
	Opis[54].setCharacterSize(40);
	Opis[54].setPosition(10, 70);
	Opis[54].setString(L"+ Ubierz się w ciepłą odzież, która ochroni Cię przed wiatrem ");

	Opis[55].setFont(font);
	Opis[55].setFillColor(sf::Color::Black);
	Opis[55].setCharacterSize(40);
	Opis[55].setPosition(10, 20);
	Opis[55].setString(L"+ Przewidywane są silne podmuchy wiatru");

	Opis[56].setFont(font);
	Opis[56].setFillColor(sf::Color::Black);
	Opis[56].setCharacterSize(40);
	Opis[56].setPosition(10, 70);
	Opis[56].setString(L"+ Ubierz się w ciepłą odzież chroniącą przed porywistym wiatrem ");


	/*Opis[57].setFont(font);
	Opis[57].setFillColor(sf::Color::Black);
	Opis[57].setCharacterSize(40);
	Opis[57].setPosition(10, 20);
	Opis[57].setString(L"+ Przewiduje się bardzo silne podmuchy wiatru");

	Opis[58].setFont(font);
	Opis[58].setFillColor(sf::Color::Black);
	Opis[58].setCharacterSize(40);
	Opis[58].setPosition(10, 70);
	Opis[58].setString(L"+ Nie wychodź bez potrzeby z domu. W razie konieczności ubierz się w odzież ochronną. ");*/

	Opis[59].setFont(font);
	Opis[59].setFillColor(sf::Color::Black);
	Opis[59].setCharacterSize(40);
	Opis[59].setPosition(10, 20);
	Opis[59].setString(L"+ Przewiduje się powstanie burz w najbliższym czasie");

	Opis[60].setFont(font);
	Opis[60].setFillColor(sf::Color::Black);
	Opis[60].setCharacterSize(40);
	Opis[60].setPosition(10, 70);
	Opis[60].setString(L"+ Najlepiej nie wychodzić w tym czasie z domu");

	Opis[61].setFont(font);
	Opis[61].setFillColor(sf::Color::Black);
	Opis[61].setCharacterSize(40);
	Opis[61].setPosition(10, 120);
	Opis[61].setString(L"+ Jeżeli musisz, ubierz się w ciepłą odzież przeciwdeszczową i unikaj lasów");

	Opis[62].setFont(font);
	Opis[62].setFillColor(sf::Color::Black);
	Opis[62].setCharacterSize(40);
	Opis[62].setPosition(10, 20);
	Opis[62].setString(L"+ Przewiduje się wystąpienie ekstremalnie niebezpiecznych zjawisk!");

	Opis[63].setFont(font);
	Opis[63].setFillColor(sf::Color::Black);
	Opis[63].setCharacterSize(40);
	Opis[63].setPosition(10, 70);
	Opis[63].setString(L"+ Nie wychodź z domu! Zabezpiecz ruchome elementy");
}


void Opis_gry::rysuj(sf::RenderWindow& window, int ktory)
{

	//for (int i = 0; i < 13; i++)
	//{
		window.draw(Opis[ktory]);
	//}

}


class Ekran
{

private:
	sf::Font font;
	sf::Text Punkty, Time, Naz;
	sf::Vector2f position;
	std::ostringstream oss;
	int c;
	int d;
	//std::string Nazwa;

public:

	void rys(sf::RenderWindow& window);
	void Czas(int d_in, int c_in, int b_in);
	void mrys(sf::RenderWindow& window);
	void mCzas(int d_in, int c_in, int b_in);
	void srys(sf::RenderWindow& window);
	void sCzas(int d_in, int c_in, int b_in);
	void msrys(sf::RenderWindow& window);
	void msCzas(int d_in, int c_in, int b_in);


	void rysy(sf::RenderWindow& window);
	void Czasy(int d_in, int c_in, int b_in);
	void rysyk(sf::RenderWindow& window);
	void Czasyk(int d_in, int c_in, int b_in);
	void rysymin(sf::RenderWindow& window);
	void Czasymin(int d_in, int c_in, int b_in);
	void rysyminsec(sf::RenderWindow& window);
	void Czasyminsec(int d_in, int c_in, int b_in);


};



void Ekran::Czas(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(50);
	Time.setPosition(1200, 0);
	Time.setString(std::to_string(d_in) + ":" + std::to_string(c_in) + ":" + std::to_string(b_in));
}

void Ekran::rys(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::mCzas(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(50);
	Time.setPosition(1200, 0);
	Time.setString(std::to_string(d_in) + ":0" + std::to_string(c_in) + ":" + std::to_string(b_in));
}

void Ekran::mrys(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::sCzas(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(50);
	Time.setPosition(1200, 0);
	Time.setString(std::to_string(d_in) + ":" + std::to_string(c_in) + ":0" + std::to_string(b_in));
}

void Ekran::srys(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::msCzas(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(50);
	Time.setPosition(1200, 0);
	Time.setString(std::to_string(d_in) + ":0" + std::to_string(c_in) + ":0" + std::to_string(b_in));
}

void Ekran::msrys(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::Czasy(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(200);
	Time.setPosition(350, 250);
	Time.setString(std::to_string(d_in) + ":" + std::to_string(c_in) + ":" + std::to_string(b_in));
}

void Ekran::rysy(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::Czasyk(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(200);
	Time.setPosition(350, 250);
	Time.setString(std::to_string(d_in) + ":" + std::to_string(c_in) + ":0" + std::to_string(b_in));
}

void Ekran::rysyk(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::Czasymin(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(200);
	Time.setPosition(350, 250);
	Time.setString(std::to_string(d_in) + ":0" + std::to_string(c_in) + ":" + std::to_string(b_in));
}

void Ekran::rysymin(sf::RenderWindow& window)
{
	window.draw(Time);
}

void Ekran::Czasyminsec(int d_in, int c_in, int b_in)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		return;
	}

	Time.setFont(font);
	Time.setFillColor(sf::Color::Blue);
	Time.setCharacterSize(200);
	Time.setPosition(350, 250);
	Time.setString(std::to_string(d_in) + ":0" + std::to_string(c_in) + ":0" + std::to_string(b_in));
}

void Ekran::rysyminsec(sf::RenderWindow& window)
{
	window.draw(Time);
}

//Ubiór
class Deszczy

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Deszczy;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getDeszczy() { return Deszczy; }
	sf::Vector2f getPozycja() {
		return Deszczy.getPosition();
	}



};

void Deszczy::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("LekkiDeszcz.jpg");
	Deszczy.setTexture(tekstura);
	Deszczy.setPosition(position);
}

class Deszczym

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Deszczym;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getDeszczym() { return Deszczym; }
	sf::Vector2f getPozycja() {
		return Deszczym.getPosition();
	}



};

void Deszczym::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("DeszczMocny.jpg");
	Deszczym.setTexture(tekstura);
	Deszczym.setPosition(position);
}

class WiatrL

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite WiatrL;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getWiatrL() { return WiatrL; }
	sf::Vector2f getPozycja() {
		return WiatrL.getPosition();
	}



};

void WiatrL::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("WiatrU.jpg");
	WiatrL.setTexture(tekstura);
	WiatrL.setPosition(position);
}

class Ldeszczwiatr

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Ldeszczwiatr;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getLdeszczwiatr() { return Ldeszczwiatr; }
	sf::Vector2f getPozycja() {
		return Ldeszczwiatr.getPosition();
	}



};

void Ldeszczwiatr::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("LDeszczWiatr.jpg");
	Ldeszczwiatr.setTexture(tekstura);
	Ldeszczwiatr.setPosition(position);
}

class ZlaPogoda

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite ZlaPogoda;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getZlaPogoda() { return ZlaPogoda; }
	sf::Vector2f getPozycja() {
		return ZlaPogoda.getPosition();
	}



};

void ZlaPogoda::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("ZlaPogoda.jpg");
	ZlaPogoda.setTexture(tekstura);
	ZlaPogoda.setPosition(position);
}

class BZlaPogoda

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite BZlaPogoda;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getBZlaPogoda() { return BZlaPogoda; }
	sf::Vector2f getPozycja() {
		return BZlaPogoda.getPosition();
	}



};

void BZlaPogoda::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("TragPogoda.jpg");
	BZlaPogoda.setTexture(tekstura);
	BZlaPogoda.setPosition(position);
}


class Upal

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Upal;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getUpal() { return Upal; }
	sf::Vector2f getPozycja() {
		return Upal.getPosition();
	}



};

void Upal::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Upal.jpg");
	Upal.setTexture(tekstura);
	Upal.setPosition(position);
}

class NormTemp

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite NormTemp;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getNormTemp() { return NormTemp; }
	sf::Vector2f getPozycja() {
		return NormTemp.getPosition();
	}


};

void NormTemp::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("NormTemp.png");
	NormTemp.setTexture(tekstura);
	NormTemp.setPosition(position);
}

class Swiatr

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Swiatr;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getSwiatr() { return Swiatr; }
	sf::Vector2f getPozycja() {
		return Swiatr.getPosition();
	}


};

void Swiatr::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("SWiatr.jpg");
	Swiatr.setTexture(tekstura);
	Swiatr.setPosition(position);
}

class Bzimno

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Bzimno;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getBzimno() { return Bzimno; }
	sf::Vector2f getPozycja() {
		return Bzimno.getPosition();
	}


};

void Bzimno::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("BZimno.png");
	Bzimno.setTexture(tekstura);
	Bzimno.setPosition(position);
}

class Mroz

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite Mroz;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getMroz() { return Mroz; }
	sf::Vector2f getPozycja() {
		return Mroz.getPosition();
	}


};

void Mroz::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("Mroz.png");
	Mroz.setTexture(tekstura);
	Mroz.setPosition(position);
}

class STemp

{
private:
	sf::Vector2f position;
	float dx, dy;
	sf::Texture tekstura;
	sf::Sprite STemp;
	sf::IntRect obszar;


public:

	void pozycja(float dx_in, float dy_in);

	sf::Sprite getSTemp() { return STemp; }
	sf::Vector2f getPozycja() {
		return STemp.getPosition();
	}


};

void STemp::pozycja(float dx_in, float dy_in)
{
	position.x = dx_in;
	position.y = dy_in;
	tekstura.loadFromFile("STemp.png");
	STemp.setTexture(tekstura);
	STemp.setPosition(position);
}


int main()
{
	sf::RenderWindow window(sf::VideoMode(1400, 788), "Aplikacja pogodowa", sf::Style::Titlebar | sf::Style::Close);
	int temperatura =0, wiatry = 0 , temperaturap = 0, desz = 0, wilgotnosc = 0, CAPE = 0, temp = 0, KI = 0, TT = 0, SRH1 = 0, SRH2 = 0, CIN = 0, LI = 0, decyzja = 0, temp1=0,desz1 = 0,wilgotnosc1 = 0,CAPE1 = 0,KI1 = 0,TT1 = 0,SRH11 = 0,SRH21 = 0,CIN1 =0,LI1 =0, k=0;
	
	SYSTEMTIME st;
	//GetSystemTime(&st);

	Ekran Czas;
	Ekran mCzas;
	Ekran msCzas;
	Ekran sCzas;
	Ekran Czasy;
	Ekran Czasyk;
	Ekran Czasymin;
	Ekran Czasyminsec;
	Deszczy deszczy;
	deszczy.pozycja(350, 200);
	Deszczym deszczym;
	deszczym.pozycja(350, 200);
	WiatrL wiatrL;
	wiatrL.pozycja(350, 200);
	Ldeszczwiatr ldeszczwiatr;
	ldeszczwiatr.pozycja(350, 200);
	ZlaPogoda zlapogoda;
	zlapogoda.pozycja(350, 200);
	BZlaPogoda bzlapogoda;
	bzlapogoda.pozycja(350, 200);
	Upal upal;
	upal.pozycja(350, 200);
	NormTemp normtemp;
	normtemp.pozycja(350, 200);
	Swiatr swiatr;
	swiatr.pozycja(350, 200);
	Bzimno bzimno;
	bzimno.pozycja(350, 200);
	Mroz mroz;
	mroz.pozycja(350,200);
	STemp stemp;
	stemp.pozycja(350, 200);
	std::cout << "Podaj aktualna temperature: ";
	std::cin >> temperaturap;
	std::cout << "Podaj temperature za 3h: ";
	std::cin >> temperatura;
	temp = temperaturap - temperatura;
	std::cout << "Podaj opady deszczu: ";
	std::cin >> desz;
	std::cout << "Podaj wilgotnosc wzgledna powietrza: ";
	std::cin >> wilgotnosc;
	std::cout << "Podaj wartosc CAPE: "; // 1000< słaba, 1000-2500 średnia, 2500-3000 silna, >3000 bardzo silna
	std::cin >> CAPE;
	std::cout << "Podaj wartosc indeksu Li: "; //Powyżej 0 burze nie są możliwe,  od -1 do -5 możliwe, prawdopodobne -6 -7 burze wystąpią, powyżej -7 ekstremalne szanse
	std::cin >> LI;
	std::cout << "Podaj wskaznik CIN: "; // 0-50 słaba inwersja, 51-200 średnia, 200 silna - uniemożliwia burze
	std::cin >> CIN;
	std::cout << "Podaj parametr SRH 0-1km: "; // powyżej 150 to silna konwekcja sprzyjają silnym trąbom powietrznym
	std::cin >> SRH1;
	std::cout << "Podaj parametr SRH 0-3km: "; // powyżej 200 to silna konwekcja sprzyjająca mezocyklonom
	std::cin >> SRH2;
	std::cout << "Podaj indeks TT: "; // poniżej 44 brak konwekcji, 44-50 wiatr  poniżej 64 km/h oraz grad do 1 cm powyżej 54 wiatr powyżej 92km/h oraz grad powyżej 2 cm
	std::cin >> TT;
	std::cout << "Podaj parametr KI: "; // do 15 brak burz, koło 30 mamy 50%, do 36 80%, wyżej 100%
	std::cin >> KI;
	


	if (temp<5)
	{
		temp1 = 1;
	}
	if (temp >5 && temp<10 )
	{
		temp1 = 2;
	}
	if (temp > 10 && temp <= 15)
	{
		temp1 = 3;
	}
	if (temp > 15)
	{
		temp1 = 4;
	}
	//Wilgotnosc
	if (wilgotnosc < 60)
	{
		wilgotnosc1 = 0;
	}
	if (wilgotnosc > 60 && wilgotnosc < 80)
	{
		wilgotnosc1 = 1;
	}
	if (wilgotnosc > 80 && wilgotnosc < 90)
	{
		wilgotnosc1 = 2;
	}
	if (wilgotnosc > 90)
	{
		wilgotnosc1 = 3;
	}
	if (wilgotnosc > 95)
	{
		wilgotnosc1 = 4;
	}
	//CAPE
	if (CAPE < 200)
	{
		CAPE1 = 0;
	}
	if (CAPE > 200 && CAPE <1200)
	{
		CAPE1 = 1;
	}
	if (CAPE > 1200 && CAPE < 2000)
	{
		CAPE1 = 2;
	}
	if (CAPE > 2000 && CAPE < 2500)
	{
		CAPE1 = 3;
	}
	if (CAPE > 2500)
	{
		CAPE1 = 4;
	}
	// Li
	if (LI > 0)
	{
		LI1 = 0;
	}
	if (LI < 0 && LI >= -2)
	{
		LI1 = 1;
	}
	if (LI <= -3 && LI > -4)
	{
		LI1 = 2;
	}
	if (LI <= -4 && LI > -5)
	{
		LI1 = 3;
	}
	if (LI < -6)
	{
		LI1 = 4;
	}
	//CIN
	if (CIN > 200)
	{
		CIN1 = 0;
	}
	if (CIN < 200 && CIN >=150)
	{
		CIN1 = 1;
	}
	if (CIN < 150 && CIN >= 100)
	{
		CIN1 = 2;
	}
	if (CIN < 100 && CIN >= 50)
	{
		CIN1 = 3;
	}
	if (CIN < 50)
	{
		CIN1 = 4;
	}
	//TT
	if (TT < 44)
	{
		TT1 = 0;
	}
	if (TT > 44 && TT <=48)
	{
		TT1 = 1;
	}
	if (TT > 48 && TT <=54)
	{
		TT1 = 2;
	}
	if (TT > 54 && TT <= 58)
	{
		TT1 = 3;
	}
	if (TT > 58)
	{
		TT1 = 4;
	}
	//KI
	if (KI < 15)
	{
		KI1 = 0;
	}
	if (KI > 15 && KI <=25)
	{
		KI1 = 1;
	}
	if (KI > 25 && KI <= 35)
	{
		KI1 = 2;
	}
	if (KI > 35 && KI <= 40)
	{
		KI1 = 3;
	}
	if (KI > 40)
	{
		KI1 = 4;
	}
	decyzja = temp1 + wilgotnosc1 + CAPE1 + LI1 + CIN1 + TT1 + KI1;
	std::cout << temp1 << wilgotnosc1<<CAPE1<<LI1<<CIN1<<TT1<<KI1;
	std::cout << "Decyzja: " << decyzja;
	napis napis;
	napis.pozycja(0, 0);
	Menu menu(window.getSize().x, window.getSize().y);
	int menu_selected_flag = 0;
	Opis_gry Opis;
	
	Deszcz deszcz;
	deszcz.pozycja(295, 290);
	Wiatr wiatr;
	wiatr.pozycja(580, 290);
	Start start;
	start.pozycja(0, 0);
	Ostrzezenie ostrzezenie;
	ostrzezenie.pozycja(20, 610);
	Tornado tornado;
	tornado.pozycja(900, 330);
	Wczyt wczyt;
	wczyt.pozycja(0, 0);
	Burza burza;
	burza.pozycja(50, 330);

	while (1) {
		

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed)
				{

					if (event.key.code == sf::Keyboard::Up)
					{
						myDelay(150);
						menu.moveUp();
					}

					if (event.key.code == sf::Keyboard::Down)
					{
						myDelay(150);
						menu.moveDown();
					}
					if (menu_selected_flag == 0)
					{
						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 0)
						{
							menu_selected_flag = 1;

						}
						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 1)
						{
							menu_selected_flag = 2;

						}

						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 2)
						{
							menu_selected_flag = 3;
						}

						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 3)
						{
							menu_selected_flag = 4;
						}

						if (event.key.code == sf::Keyboard::Enter && menu.getSelectedItem() == 4)
						{
							menu_selected_flag = 5;
							window.close();
						}

					}


				}
			}
			

			if (menu_selected_flag == 0) {
				window.clear();
				window.draw(napis.getNapis());
				menu.draw(window);
				window.display();
			}
			if (menu_selected_flag == 1)
			{
				window.clear();
				GetSystemTime(&st);
				//std::cout << "Biezaca godzina  to " << st.wHour << std::endl;
				//std::cout << "Biezaca minuta  to " << st.wMinute << std::endl;
				//std::cout << "Biezaca sekunda  to " << st.wSecond << std::endl;


				if (st.wSecond >= 10 && st.wMinute >= 10)
				{
					Czas.Czas(st.wHour + 1, st.wMinute, st.wSecond);
					myDelay(100);
					window.draw(wczyt.getWczyt());
					//Opis.rysuj(window, 1);
					//window.draw(deszcz.getDeszcz());
					//window.draw(wiatr.getWiatr());
					//window.draw(ostrzezenie.getOstrzezenie());
					

					//Opis.rysuj(window, 18);
					//Opis.rysuj(window, 23);
					//Nagłówki
					Opis.rysuj(window, 29);
					Opis.rysuj(window, 30);
					Opis.rysuj(window, 31);
					//Deszcz
					if (desz == 0)
					{
						Opis.rysuj(window, 15);
					}
					if (desz > 0 && desz <= 10)
					{
						Opis.rysuj(window, 16);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 10 && desz <= 30)
					{
						Opis.rysuj(window, 17);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 30 && desz <= 55)
					{
						Opis.rysuj(window, 18);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 55)
					{
						Opis.rysuj(window, 19);
						window.draw(deszcz.getDeszcz());
					}

					//Wiatr i grad
					if (TT > 0 && TT < 35)
					{
						Opis.rysuj(window, 8);
					}
					if (TT >= 35 && TT < 40)
					{
						Opis.rysuj(window, 9);
					}
					if (TT >= 40 && TT < 44)
					{
						Opis.rysuj(window, 10);
					}
					if (TT >= 44 && TT < 50)
					{
						Opis.rysuj(window, 11);
						Opis.rysuj(window, 3);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());
					}
					if (TT >= 50 && TT < 54)
					{
						Opis.rysuj(window, 12);
						Opis.rysuj(window, 4);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());

					}
					if (TT >= 54)
					{
						if (SRH2 < 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 5);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						// Silne porywy wiatru przekraczające 90 km/h, grad powyżej 3 cm
						if (SRH2 >= 150 && SRH2 <= 180)
						{
							Opis.rysuj(window, 1);
							// Porywy wiatru przekraczające 100 km/h, grad do 5 cm
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 6);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						if (SRH2 > 180)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 14);
							Opis.rysuj(window, 7);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
							// Porywy wiatru przekraczające 120 km/h, grad przekraczajacy 8 cm
						}
					}
					if (decyzja < 4)
					{
						Opis.rysuj(window, 20);
					}

					if (CAPE > 100 && LI <= 0 && CIN < 200 && TT > 44 && KI > 15) // Warunek na występowanie burz
					{

						
						//Tornado
						if (SRH1 > 60 && SRH1 <= 90)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 25);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							//Małe ryzyko wystąpienia tornada
						}
						if (SRH1 > 90 && SRH1 < 110)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 26);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Średnie ryzyko wystąpienia tornada o słabej sile
						}
						if (SRH1 > 110 && SRH1 <= 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 27);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o średniej sile
						}
						if (SRH1 > 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 28);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o duże znacznej sile
						}
						// 


						if (SRH2 > 80 && SRH2 <= 100)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 32);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 100 && SRH2 <= 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 33);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 34);
							window.draw(ostrzezenie.getOstrzezenie());
							//Poważne ryzyko powstania mezocyklonu
						}


						//Burze
						if (decyzja >= 3 && decyzja <= 9)
						{
							Opis.rysuj(window, 21);
							window.draw(burza.getBurza());
							// Słabe burze
						}
						if (decyzja > 9 && decyzja <= 15)
						{
							Opis.rysuj(window, 22);
							window.draw(burza.getBurza());
							// Średnie burze
						}
						if (decyzja > 15 && decyzja <= 22)
						{
							Opis.rysuj(window, 23);
							window.draw(burza.getBurza());
							// Silne burze
						}
						if (decyzja > 22)
						{
							Opis.rysuj(window, 24);
							window.draw(burza.getBurza());
							//Ekstremalnie silne burze
						}
					}
					else
					{
						Opis.rysuj(window, 20);
					}
					
					Czas.rys(window);
					window.display();
					myDelay(100);

				}
				if (st.wSecond >= 10 && st.wMinute < 10)
				{
					Czas.mCzas(st.wHour + 1, st.wMinute, st.wSecond);
					myDelay(100);
					window.draw(wczyt.getWczyt());
					Opis.rysuj(window, 29);
					Opis.rysuj(window, 30);
					Opis.rysuj(window, 31);
					if (desz == 0)
					{
						Opis.rysuj(window, 15);
					}
					if (desz > 0 && desz <= 10)
					{
						Opis.rysuj(window, 16);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 10 && desz <= 30)
					{
						Opis.rysuj(window, 17);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 30 && desz <= 55)
					{
						Opis.rysuj(window, 18);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 55)
					{
						Opis.rysuj(window, 19);
						window.draw(deszcz.getDeszcz());
					}

					//Wiatr i grad
					if (TT > 0 && TT < 35)
					{
						Opis.rysuj(window, 8);
					}
					if (TT >= 35 && TT < 40)
					{
						Opis.rysuj(window, 9);
					}
					if (TT >= 40 && TT < 44)
					{
						Opis.rysuj(window, 10);
					}
					if (TT >= 44 && TT < 50)
					{
						Opis.rysuj(window, 11);
						Opis.rysuj(window, 3);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());
					}
					if (TT >= 50 && TT < 54)
					{
						Opis.rysuj(window, 12);
						Opis.rysuj(window, 4);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());

					}
					if (TT >= 54)
					{
						if (SRH2 < 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 5);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						// Silne porywy wiatru przekraczające 90 km/h, grad powyżej 3 cm
						if (SRH2 >= 150 && SRH2 <= 180)
						{
							Opis.rysuj(window, 1);
							// Porywy wiatru przekraczające 100 km/h, grad do 5 cm
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 6);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						if (SRH2 > 180)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 14);
							Opis.rysuj(window, 7);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
							// Porywy wiatru przekraczające 120 km/h, grad przekraczajacy 8 cm
						}
					}
					if (decyzja < 4)
					{
						Opis.rysuj(window, 20);
					}

					if (CAPE > 100 && LI <= 0 && CIN < 200 && TT > 44 && KI > 15) // Warunek na występowanie burz
					{


						//Tornado
						if (SRH1 > 60 && SRH1 <= 90)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 25);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							//Małe ryzyko wystąpienia tornada
						}
						if (SRH1 > 90 && SRH1 < 110)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 26);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Średnie ryzyko wystąpienia tornada o słabej sile
						}
						if (SRH1 > 110 && SRH1 <= 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 27);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o średniej sile
						}
						if (SRH1 > 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 28);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o duże znacznej sile
						}
						// 


						if (SRH2 > 80 && SRH2 <= 100)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 32);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 100 && SRH2 <= 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 33);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 34);
							window.draw(ostrzezenie.getOstrzezenie());
							//Poważne ryzyko powstania mezocyklonu
						}


						//Burze
						if (decyzja >= 3 && decyzja <= 9)
						{
							Opis.rysuj(window, 21);
							window.draw(burza.getBurza());
							// Słabe burze
						}
						if (decyzja > 9 && decyzja <= 15)
						{
							Opis.rysuj(window, 22);
							window.draw(burza.getBurza());
							// Średnie burze
						}
						if (decyzja > 15 && decyzja <= 22)
						{
							Opis.rysuj(window, 23);
							window.draw(burza.getBurza());
							// Silne burze
						}
						if (decyzja > 22)
						{
							Opis.rysuj(window, 24);
							window.draw(burza.getBurza());
							//Ekstremalnie silne burze
						}
					}
					else
					{
						Opis.rysuj(window, 20);
					}
					Czas.mrys(window);
					window.display();
					myDelay(100);
				}

				if (st.wSecond < 10 && st.wMinute >= 10)
				{
					Czas.sCzas(st.wHour + 1, st.wMinute, st.wSecond);
					myDelay(100);
					window.draw(wczyt.getWczyt());
					//Opis.rysuj(window, 1);
					//window.draw(deszcz.getDeszcz());
					//window.draw(wiatr.getWiatr());
					//window.draw(ostrzezenie.getOstrzezenie());
					//Opis.rysuj(window, 18);
					//Opis.rysuj(window, 23);
					//Nagłówki
					Opis.rysuj(window, 29);
					Opis.rysuj(window, 30);
					Opis.rysuj(window, 31);
					if (desz == 0)
					{
						Opis.rysuj(window, 15);
					}
					if (desz > 0 && desz <= 10)
					{
						Opis.rysuj(window, 16);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 10 && desz <= 30)
					{
						Opis.rysuj(window, 17);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 30 && desz <= 55)
					{
						Opis.rysuj(window, 18);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 55)
					{
						Opis.rysuj(window, 19);
						window.draw(deszcz.getDeszcz());
					}

					//Wiatr i grad
					if (TT > 0 && TT < 35)
					{
						Opis.rysuj(window, 8);
					}
					if (TT >= 35 && TT < 40)
					{
						Opis.rysuj(window, 9);
					}
					if (TT >= 40 && TT < 44)
					{
						Opis.rysuj(window, 10);
					}
					if (TT >= 44 && TT < 50)
					{
						Opis.rysuj(window, 11);
						Opis.rysuj(window, 3);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());
					}
					if (TT >= 50 && TT < 54)
					{
						Opis.rysuj(window, 12);
						Opis.rysuj(window, 4);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());

					}
					if (TT >= 54)
					{
						if (SRH2 < 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 5);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						// Silne porywy wiatru przekraczające 90 km/h, grad powyżej 3 cm
						if (SRH2 >= 150 && SRH2 <= 180)
						{
							Opis.rysuj(window, 1);
							// Porywy wiatru przekraczające 100 km/h, grad do 5 cm
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 6);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						if (SRH2 > 180)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 14);
							Opis.rysuj(window, 7);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
							// Porywy wiatru przekraczające 120 km/h, grad przekraczajacy 8 cm
						}
					}
					if (decyzja < 4)
					{
						Opis.rysuj(window, 20);
					}

					if (CAPE > 100 && LI <= 0 && CIN < 200 && TT > 44 && KI > 15) // Warunek na występowanie burz
					{


						//Tornado
						if (SRH1 > 60 && SRH1 <= 90)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 25);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							//Małe ryzyko wystąpienia tornada
						}
						if (SRH1 > 90 && SRH1 < 110)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 26);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Średnie ryzyko wystąpienia tornada o słabej sile
						}
						if (SRH1 > 110 && SRH1 <= 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 27);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o średniej sile
						}
						if (SRH1 > 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 28);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o duże znacznej sile
						}
						// 


						if (SRH2 > 80 && SRH2 <= 100)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 32);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 100 && SRH2 <= 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 33);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 34);
							window.draw(ostrzezenie.getOstrzezenie());
							//Poważne ryzyko powstania mezocyklonu
						}


						//Burze
						if (decyzja >= 3 && decyzja <= 9)
						{
							Opis.rysuj(window, 21);
							window.draw(burza.getBurza());
							// Słabe burze
						}
						if (decyzja > 9 && decyzja <= 15)
						{
							Opis.rysuj(window, 22);
							window.draw(burza.getBurza());
							// Średnie burze
						}
						if (decyzja > 15 && decyzja <= 22)
						{
							Opis.rysuj(window, 23);
							window.draw(burza.getBurza());
							// Silne burze
						}
						if (decyzja > 22)
						{
							Opis.rysuj(window, 24);
							window.draw(burza.getBurza());
							//Ekstremalnie silne burze
						}
					}
					else
					{
						Opis.rysuj(window, 20);
					}

					Czas.srys(window);
					window.display();
					myDelay(100);
				}

				if (st.wSecond < 10 && st.wMinute < 10)
				{
					Czas.msCzas(st.wHour + 1, st.wMinute, st.wSecond);
					myDelay(100);
					window.draw(wczyt.getWczyt());
					//Opis.rysuj(window, 1);
					//window.draw(deszcz.getDeszcz());
					//window.draw(wiatr.getWiatr());
					//window.draw(ostrzezenie.getOstrzezenie());
					//Opis.rysuj(window, 18);
					//Opis.rysuj(window, 23);
					//Nagłówki
					Opis.rysuj(window, 29);
					Opis.rysuj(window, 30);
					Opis.rysuj(window, 31);

					if (desz == 0)
					{
						Opis.rysuj(window, 15);
					}
					if (desz > 0 && desz <= 10)
					{
						Opis.rysuj(window, 16);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 10 && desz <= 30)
					{
						Opis.rysuj(window, 17);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 30 && desz <= 55)
					{
						Opis.rysuj(window, 18);
						window.draw(deszcz.getDeszcz());
					}
					if (desz > 55)
					{
						Opis.rysuj(window, 19);
						window.draw(deszcz.getDeszcz());
					}

					//Wiatr i grad
					if (TT > 0 && TT < 35)
					{
						Opis.rysuj(window, 8);
					}
					if (TT >= 35 && TT < 40)
					{
						Opis.rysuj(window, 9);
					}
					if (TT >= 40 && TT < 44)
					{
						Opis.rysuj(window, 10);
					}
					if (TT >= 44 && TT < 50)
					{
						Opis.rysuj(window, 11);
						Opis.rysuj(window, 3);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());
					}
					if (TT >= 50 && TT < 54)
					{
						Opis.rysuj(window, 12);
						Opis.rysuj(window, 4);
						window.draw(ostrzezenie.getOstrzezenie());
						window.draw(wiatr.getWiatr());

					}
					if (TT >= 54)
					{
						if (SRH2 < 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 5);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						// Silne porywy wiatru przekraczające 90 km/h, grad powyżej 3 cm
						if (SRH2 >= 150 && SRH2 <= 180)
						{
							Opis.rysuj(window, 1);
							// Porywy wiatru przekraczające 100 km/h, grad do 5 cm
							Opis.rysuj(window, 13);
							Opis.rysuj(window, 6);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
						}
						if (SRH2 > 180)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 14);
							Opis.rysuj(window, 7);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(wiatr.getWiatr());
							// Porywy wiatru przekraczające 120 km/h, grad przekraczajacy 8 cm
						}
					}
					if (decyzja < 4)
					{
						Opis.rysuj(window, 20);
					}

					if (CAPE > 100 && LI <= 0 && CIN < 200 && TT > 44 && KI > 15) // Warunek na występowanie burz
					{


						//Tornado
						if (SRH1 > 60 && SRH1 <= 90)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 25);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							//Małe ryzyko wystąpienia tornada
						}
						if (SRH1 > 90 && SRH1 < 110)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 26);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Średnie ryzyko wystąpienia tornada o słabej sile
						}
						if (SRH1 > 110 && SRH1 <= 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 27);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o średniej sile
						}
						if (SRH1 > 130)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 28);
							window.draw(ostrzezenie.getOstrzezenie());
							window.draw(tornado.getTornado());
							// Duże ryzyko wystąpienia tornada o duże znacznej sile
						}
						// 


						if (SRH2 > 80 && SRH2 <= 100)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 32);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 100 && SRH2 <= 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 33);
							window.draw(ostrzezenie.getOstrzezenie());
							//Możliwe powstanie mezocyklonu
						}
						if (SRH2 > 150)
						{
							Opis.rysuj(window, 1);
							Opis.rysuj(window, 34);
							window.draw(ostrzezenie.getOstrzezenie());
							//Poważne ryzyko powstania mezocyklonu
						}


						//Burze
						if (decyzja >= 3 && decyzja <= 9)
						{
							Opis.rysuj(window, 21);
							window.draw(burza.getBurza());
							// Słabe burze
						}
						if (decyzja > 9 && decyzja <= 15)
						{
							Opis.rysuj(window, 22);
							window.draw(burza.getBurza());
							// Średnie burze
						}
						if (decyzja > 15 && decyzja <= 22)
						{
							Opis.rysuj(window, 23);
							window.draw(burza.getBurza());
							// Silne burze
						}
						if (decyzja > 22)
						{
							Opis.rysuj(window, 24);
							window.draw(burza.getBurza());
							//Ekstremalnie silne burze
						}
					}
					else
					{
						Opis.rysuj(window, 20);
					}
					Czas.msrys(window);
					window.display();
					myDelay(100);
				}
				if (event.key.code == sf::Keyboard::BackSpace)
				{
					menu_selected_flag = 0;
				}
			}

			if (menu_selected_flag == 2) {
				window.clear();
				//wiatry, temperatura, desz
				window.draw(wczyt.getWczyt());
				if (desz == 0 && TT <= 44 && decyzja < 8)
				{
					if (temperatura > 28)
					{
						window.draw(upal.getUpal());
						Opis.rysuj(window, 35);
						Opis.rysuj(window, 36);
						
					}
					if (temperatura > 20 && temperatura <=28)
					{
						window.draw(normtemp.getNormTemp());
						Opis.rysuj(window, 37);
						Opis.rysuj(window, 38);
					}
					if (temperatura > 10 && temperatura <= 20)
					{
						Opis.rysuj(window, 39);
						Opis.rysuj(window, 40);
					}
					if (temperatura <= 10 && temperatura >=2)
					{
						window.draw(stemp.getSTemp());
						Opis.rysuj(window, 45);
						Opis.rysuj(window, 46);
					}
					if (temperatura <2 && temperatura >=-12)
					{
						window.draw(mroz.getMroz());
						Opis.rysuj(window, 43);
						Opis.rysuj(window, 44);
					}
					if (temperatura < -12)
					{
						window.draw(bzimno.getBzimno());
						Opis.rysuj(window, 41);
						Opis.rysuj(window, 42);
					}
					k = 1;
				}
			
				if (desz > 0 && desz < 15 && decyzja < 8 && TT < 44)
				{
					window.draw(deszczy.getDeszczy());
					Opis.rysuj(window, 47);
					Opis.rysuj(window, 48);
					
				}
				if (desz > 15 && decyzja < 8 && TT < 44)
				{
					window.draw(deszczym.getDeszczym());
					Opis.rysuj(window, 49);
					Opis.rysuj(window, 50);
				}
				if (desz == 0 && TT > 44 && TT < 50 && decyzja < 8)
				{
					window.draw(wiatrL.getWiatrL());
					Opis.rysuj(window, 53);
					Opis.rysuj(window, 54);
					
				}
				if (desz == 0 && TT >=50 && decyzja < 8)
				{
					window.draw(swiatr.getSwiatr());
					Opis.rysuj(window, 55);
					Opis.rysuj(window, 56);
				}
				if (desz > 0 && TT > 44 && decyzja <8 )
				{
					window.draw(ldeszczwiatr.getLdeszczwiatr());
					Opis.rysuj(window, 51);
					Opis.rysuj(window, 52);
				}
				if (CAPE > 100 && LI <= 0 && CIN < 200 && TT > 44 && KI > 15) {
					if (decyzja > 8 && decyzja < 15)
					{
						window.draw(zlapogoda.getZlaPogoda());
						Opis.rysuj(window, 59);
						Opis.rysuj(window, 60);
						Opis.rysuj(window, 61);
						
					}
					if (decyzja >= 15)
					{
						window.draw(bzlapogoda.getBZlaPogoda());
						Opis.rysuj(window, 62);
						Opis.rysuj(window, 63);
						
					}

				}
				
				window.display();
				if (event.key.code == sf::Keyboard::BackSpace)
				{
					menu_selected_flag = 0;
				}
				myDelay(100);
			}

			if (menu_selected_flag == 3)
			{
				window.clear();
				GetSystemTime(&st);
				window.draw(start.getStart());
				//window.draw(napis.getNapis());
				//std::cout << "Biezaca godzina  to " << st.wHour << std::endl;
				//std::cout << "Biezaca minuta  to " << st.wMinute << std::endl;
				//std::cout << "Biezaca sekunda  to " << st.wSecond << std::endl;
				
				
				if (st.wSecond < 10 && st.wMinute >= 10)
				{
					window.clear();
					window.draw(start.getStart());
					Czasy.Czasyk(st.wHour + 1, st.wMinute, st.wSecond);
					Czasy.rysyk(window);
					
					myDelay(300);
				}
				if (st.wSecond >= 10 && st.wMinute >= 10)
				{
					window.clear();
					window.draw(start.getStart());
					Czasy.Czasy(st.wHour + 1, st.wMinute, st.wSecond);
					Czasy.rysy(window);
					
					myDelay(300);
				}

				if (st.wSecond >= 10 && st.wMinute < 10)
				{
					window.clear();
					window.draw(start.getStart());
					Czasy.Czasymin(st.wHour + 1, st.wMinute, st.wSecond);
					Czasy.rysymin(window);

					myDelay(300);
				}

				if (st.wSecond < 10 && st.wMinute < 10)
				{
					window.clear();
					window.draw(start.getStart());
					Czasy.Czasyminsec(st.wHour + 1, st.wMinute, st.wSecond);
					Czasy.rysyminsec(window);

					myDelay(300);
				}

				std::cout << st.wSecond;
				window.display();
				myDelay(100);
				if (event.key.code == sf::Keyboard::Escape)
				{
					menu_selected_flag = 0;
				}
			}
		}
		
	}
	return 0;
}
#include<iostream>
#include "SFML/Graphics.hpp"
using namespace std;
int main() {
	//game set up (you'll need these lines in every game)
	sf::RenderWindow screen(sf::VideoMode(800, 800), "SFML scaling"); //set up screen
	sf::Event event; //set up event queue
	sf::Clock clock; //set up the clock (needed for game timing)
	const float FPS = 60.0f; //FPS
	screen.setFramerateLimit(FPS); //set FPS

	//load in images
	sf::Texture link;
	link.loadFromFile("image.jpg");
	sf::Sprite LinkPic;
	LinkPic.setTexture(link);
	//you can add scaling stuff here
	// set the absolute scale of the entity
	LinkPic.setScale(2.f, .8f);

	// scale the entity relatively to its current scale
	LinkPic.scale(0.5f, 0.5f);

	// retrieve the absolute scale of the entity
	sf::Vector2f scale = LinkPic.getScale(); // = (2, 0.8)

	//################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
	while (screen.isOpen()) {//keep window open until user shuts it down

		while (screen.pollEvent(event)) { //look for events-----------------------

			//this checks if the user has clicked the little "x" button in the top right corner
			if (event.type == sf::Event::EventType::Closed)
				screen.close();

		}//end event loop---------------------------------------------------------------

		//physics section---------------------------------------------------------------


		//you can add rotation stuff here
		
		LinkPic.setRotation(55.f);

	
		LinkPic.rotate(10.f);

		
		float rotation = LinkPic.getRotation(); // = 55

		//render section-----------------------------------------
		screen.clear(); //wipes screen, without this things smear

		screen.draw(LinkPic); 

			LinkPic.setPosition(250, 250);

		

			
			// get the bounding box of the entity
			sf::FloatRect boundingBox = LinkPic.getGlobalBounds();

			// check collision with a point
			sf::Vector2f point(250, 250);
			if (boundingBox.contains(point))
			{
				// collision!
				cout << "collision!" << endl;
			}

			// check collision with another box (like the bounding box of another entity)
			sf::FloatRect otherBox(150, 50, 100, 100);
			if (boundingBox.intersects(otherBox))
			{
				// collision!
			}


			


		screen.display(); //flips memory drawings onto screen

	}//######################## end game loop ###################################################################################

	cout << "goodbye!" << endl;
} //end of main

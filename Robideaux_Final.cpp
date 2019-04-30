//Program Name: Final
//Author: Hannah Robideaux
//Purpose: A game where a little dog has lost his favorite toy, you must help him find it
//Date Last Modified: 28 Apr 2019
//Description: allows the player to explore and interact with this dog's house using an action menu. Specific actions need to be done to win the game

#include <iostream>
#include <string>
using namespace std;
//since these variables are used throughout the code and never changed, this was easier
const int BEDROOM = 1; //holds the int variable for the bedroom
const int LIVINGROOM = 2; //holds the int variable for the living room
const int BACKYARD = 3; //holds the int variable for the backyard

const string Sniffables[3][4] = { //holds all the sniff objects for each room
  {"BED", "CARPET", "BOOTS", "ROOM"} , //row 0 is bedroom
  {"COUCH", "DOORMAT", "TOYBOX", "ROOM"} , //row 1 is living room
  {"GRASS", "TREE", "CAT", "ROOM"} // row 2 is backyard
};

const string Peeables[3][4] = { //Exactly the same as above, but holds the pee objects
  {"BED", "CARPET", "BOOTS", "NOTHING"} ,//bedroom
  {"COUCH", "DOORMAT", "TOYBOX", "NOTHING"} , //living room
  {"GRASS", "TREE", "CAT", "NOTHING"} //backyard
};

void DescribeRoom (int CurrentRoom, bool MovedCat) //These are the descriptions of each room that will be displayed each time the user enters that room
{
  if (CurrentRoom == BEDROOM) {
    cout << "This is me and mama's bedroom! It has the BED in it and a CARPET on the ground with mama's BOOTS on it." << endl;
    return;
  }
  if (CurrentRoom == LIVINGROOM) {
    cout << "This is the living room! It has a COUCH by the wall and a DOORMAT by the front door and my TOYBOX." << endl;
  }
  if (CurrentRoom == BACKYARD) {
    if (MovedCat == false) {
      cout << "This is the backyard!! There is GRASS everywhere and a big TREE in the corner with a CAT next to it!" << endl;
    } else { //If the cat isn' there, the cat can't be in the room description
      cout << "This is the backyard!! There is GRASS everywhere and a big TREE in the corner." << endl;
    }
  }
}

int GetAction() //Gets the user's action
{
  int Choice; //What action the player wants to take
  cout << "[Enter 1 to SNIFF. 2 to PEE. 3 to CHANGE ROOMS. 0 to EXIT GAME]" << endl;
  cin >> Choice;
  cout << endl;
  return Choice;
}

int GetSniffObject(int RoomNumber, bool MovedCat) //Gets the object of the user's action
{
  int Object; //What the player wants to sniff
  cout << "What do you want to sniff?" << endl;
  if (MovedCat == true && RoomNumber == BACKYARD) { //If you moved the cat, then the options in the BACKYARD are different (no cat)
    for (int count = 0; count < 2 ; count++) { //displays the first two options
      cout << (count+1) << " " << Sniffables[(BACKYARD-1)][count] << endl;
    }
    cout << "3 " << Sniffables[(BACKYARD-1)][3] << endl; //displays the fourth item in the array as the third option
  } else { //Displays the normal options
    for (int count = 0; count < 4; count++) {
      cout << (count+1) << " " << Sniffables[(RoomNumber-1)][count] << endl;
    }
  }
  cin >> Object;
  cout << endl;
  return Object;
}

void SniffResponse(int RoomNumber, int Object, bool SeenPurse, bool MovedCat, string ToyName)//Displays what the user learns when each object is sniffed
{
  if (RoomNumber == BEDROOM) {
    if (Object == 1) {//BED
      cout << "I sniff the bed. It smells like mama. I slept here last night with " << ToyName << ", but he wasn't there when I woke up! This must be the scene of the crime." << endl;
    }
    if (Object == 2) {//CARPET
      cout << "I sniff the carpet. It smell like shoes and it's pretty soft. I like to sleep on it. Sadly, " << ToyName << " is not on it." << endl;
    }
    if (Object == 3) { //BOOTS
      cout << "These are mama's boots! They smell like everywhere she goes. Sometimes I lay on them when I play with " << ToyName << ", but he's not there now." << endl;
    }
    if (Object == 4) {//ROOM
      cout << "This is me and mama's bedroom! It has the BED in it and a CARPET on the ground with mama's BOOTS on it." << endl;
    }
  }
  if (RoomNumber == LIVINGROOM) {
    if (Object == 1) {//COUCH
      cout << "I sniff the couch. It's big, blue, and very soft, but " << ToyName << " isn't on it." << endl;
    }
    if (Object == 2) { //DOORMAT
      cout << "This is the doormat! It has a magic power where, if I dance on it, I get to go on a walk! " << ToyName << " isn't here, though." << endl;
    }
    if (Object == 3) { //TOYBOX
      if (SeenPurse == false ) { //The first time you sniff the toybox
        cout << "I sniff my toybox. This is where mama keeps all my toys when I'm not using them. I should check if " << ToyName << " is in there!!" << endl;
        cout << "[Enter to continue.]" << endl;
        cin.ignore();
        cin.get() == '\n'; //all "enter to continue"s are just there to space things out and break up big blocks of text
        cout << "!! Mama's purse is on top and I can't open it. I can't reach her purse either! Maybe you could find something to move it??" << endl;
      } else { //Any time after the first sniff
        cout << "Mama's purse is still blocking me from opening it." << endl;
      } if (MovedCat == true) { // If you moved the cat, then you have a stick and you can move the purse
        cout << "Maybe this stick will help!! I'm gonna try to push mama's purse over..." << endl;
        cout << "[Enter to continue.]" << endl;
        cin.ignore();
        cin.get() == '\n'; //all "enter to continue"s are just there to space things out and break up big blocks of text
        cout << "It worked! Now I can get to my toys. " << ToyName << " WAS in here the whole time! Mama must have put him away while I slept. I'm so happy to have him back, thank you!!" << endl;
        return; //You win!
      }
    }
    if (Object == 4) { //ROOM
      cout << "This is the living room! It has a COUCH by the wall and a DOORMAT by the front door and my TOYBOX." << endl;
    }
  }
  if (RoomNumber == BACKYARD) {
    if (Object == 1) { //GRASS
      cout << "I sniff the grass. It smells like the outside. One time, I played with " << ToyName << " out here, but he got all muddy, so I can't do that anymore." << endl;
    }
    if (Object == 2) { //TREE
      if (MovedCat == false) {
        cout << "I sniff the tree. The tree is really big and sometimes has mean squirrels in it, but today one of the neighborhood cats, Chloe, is sitting right by it!!" << endl;
      } else {
        cout << "I sniff the tree. The tree is really big and sometimes has mean squirrels in it. Chloe is no longer there." << endl;
      }
    }
    if (Object == 3) {
      if (MovedCat == false) { //CAT
        cout << "Chloe is the cat over there, but there's no way I'm getting close enough to sniff her! She scares me! It looks like she's sitting on something though..." << endl;
      } else { //If the cat has been moved, then you can no longer interact with the cat, and ROOM becomes the third option
        cout << "This is the backyard!! There is GRASS everywhere and a big TREE in the corner." << endl;
      }
    }
    if (Object == 4) { //ROOM
      cout << "This is the backyard!! There is GRASS everywhere and a big TREE in the corner with a CAT next to it!" << endl;
    }
  }
}

int GetPeeObject(int RoomNumber, bool MovedCat) //Gets the object of the user's action
{
  int Object; //What the player wants to pee on
  cout << "What would you like to pee on?" << endl;
  if (MovedCat == true && RoomNumber == BACKYARD) { //If you moved the cat, then the options in the BACKYARD are different (no cat)
    for (int count = 0; count < 2 ; count++) { //displays the first two options
      cout << (count+1) << " " << Peeables[(BACKYARD-1)][count] << endl;
    }
    cout << "3 " << Peeables[(BACKYARD-1)][3] << endl; //displays the fourth item in the array as the third option
  }  else {
    for (int count = 0; count < 4; count++) {
      cout << (count+1) << " " << Peeables[(RoomNumber-1)][count] << endl;
    }
  }
  cin >> Object;
  cout << endl;
  return Object;
}

void PeeResponse(int RoomNumber, int Object, bool MovedCat)//Displays the response when each object is peed on. It's rarely good.
{
  if (RoomNumber == BEDROOM) {
    if (Object == 1) {//BED
      cout << "I peed on the bed! Mama wasn't happy about it... GAME OVER";
    }
    if (Object == 2) {//CARPET
      cout << "I peed on the carpet! Mama wasn't happy about it... GAME OVER";
    }
    if (Object == 3) { //BOOTS
      cout << "I peed in mama's boots! Mama REALLY wasn't happy about it... GAME OVER" << endl; //Fun fact: my dog peed in my mom's boots once, she wasn't happy about it either
    }
    if (Object == 4) { //NOTHING
      cout << "You're right, there's more important stuff to do right now." << endl;
    }
  }
  if (RoomNumber == LIVINGROOM) {
    if (Object == 1) {//COUCH
      cout << "I peed on the couch! Mama wasn't happy about it... GAME OVER";
    }
    if (Object == 2) {//DOORMAT
      cout << "I peed on the doormat! Mama wasn't happy about it... GAME OVER" << endl;
    }
    if (Object == 3) {//TOYBOX
      cout << "I peed on my toybox! Mama wasn't happy about it... GAME OVER";
    }
    if (Object == 4) { //NOTHING
      cout << "You're right, there's more important stuff to do right now." << endl;
    }
  }
  if (RoomNumber == BACKYARD) {
    if (Object == 1) { //GRASS
      cout << "I peed on the grass! Take that, grass!" << endl;
    }
    if (Object == 2) { //TREE
      if (MovedCat == false ) {
        cout << "I peed on the tree! It must have scared Chloe, cause she got up and ran away! Now there's a big stick where she was..." << endl;
        cout << "[Enter to continue.]" << endl;
        cin.ignore();
        cin.get() == '\n'; //all "enter to continue"s are just there to space things out and break up big blocks of text
        cout << "I took the stick." << endl;
      } else { //TREE after the cat has been moved
        cout << "I peed on the tree! Take that, tree!" << endl;
      }
    }
    if (Object == 3) {
      if (MovedCat == false ) { //CAT
        cout << "You must be crazy if you think I'm gonna pee on Chloe!!!" << endl;
      } else { //If the cat has been moved, then you can no longer interact with the cat, and NOTHING becomes the third option
        cout << "You're right, there's more important stuff to do right now." << endl;
      }
    }
    if (Object == 4) { //NOTHING
      cout << "You're right, there's more important stuff to do right now." << endl;
    }
  }
}

int ChangeRoom() //Gets the room the player wants to go to
{
  int CurrentRoom; //Holds the value of the room the player is currently in
  cout << "Where would you like to go?" << endl;
  cout << "1 BEDROOM \n2 LIVING ROOM \n3 BACKYARD" << endl;
  cin >> CurrentRoom;
  cout << endl;
  return CurrentRoom;
}

int main ()
{
  string Name;//Name the player gives the dog
  string ToyName;//Name the player gives the dog's toy
  int Action;//action the user wants to take
  int Object;//objects the user wants to do that action on
  int CurrentRoom = BEDROOM; //at the start, the player is in the bedroom
  bool SeenPurse = false;//at the start, the player has not seen the purse on top of the toybox
  bool MovedCat = false; //at the start, the player has not moved the cat

  cout << "Hello! I am a dog and my name is..." << endl;
  getline(cin, Name);
  cout << "My name is " << Name << "!" << endl;
  cout << "You see, I have a problem. Last night, I went to bed with my favorite toy. His name is..." << endl;
  getline(cin, ToyName);
  cout << "But this morning, when I woke up, " << ToyName << " was gone!!" << endl;
  cout << "I have no idea where he could be! You gotta help me find him. Let's search this room first." << endl;
  cout << "[Enter to continue.]" << endl; //all "enter to continue"s are just there to space things out and break up big blocks of text
  cin.get() == '\n';

  DescribeRoom(BEDROOM, MovedCat); //Starts the fun part of the game by describing the bedroom, then follows the loop below
  do {//while the user doesn't quit the game, the program calls the previous functions in an appropriate order
    Action = GetAction();
    if (Action == 1) { //Sniff
      Object = GetSniffObject(CurrentRoom, MovedCat);
      SniffResponse(CurrentRoom, Object, SeenPurse, MovedCat, ToyName);
      if (CurrentRoom == LIVINGROOM && Object == 3) {//If the user sniffs the toybox (3), they see the purse and SeenPurse is updated
        SeenPurse = true;
        if (SeenPurse == true && MovedCat == true) {//If the user sniffs the toybox (3) and both bools are true, they win the game!
          cout << "YOU WON! " << Name  << " has been reunited with " << ToyName << endl;
          return 0;
        }
      }
    }
    if (Action == 2) { //Pee
      Object = GetPeeObject(CurrentRoom, MovedCat);
      PeeResponse(CurrentRoom, Object, MovedCat);
      if (CurrentRoom != BACKYARD && Object != 4) {//backyard is safe to pee in, and Object 4 is NOTHING, so if the pee object doesn't meet these requirements, its GAME OVER
        return 0;
      }
      if (CurrentRoom == BACKYARD && Object == 2) {//If the user pees on the TREE (2) then the cat runs away and MovedCat is updated
        MovedCat = true;
      }
    }
    if (Action == 3) { //Change Room
      CurrentRoom = ChangeRoom();
      DescribeRoom(CurrentRoom, MovedCat);
    }
  } while(Action != 0); //If the user selects QUIT, it ends the program
  if (Action == 0) {
    return 0;
  }
}

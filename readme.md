# Attack of the periwinkles

# Hank's Story

Hank used to be a humble octopus, just minding his own business on the rocky shore he
lived on. He would swim from dawn till dusk in the beautiful green water every day, just enjoying
life. Then, one day the water surface started turning dark and there was hardly any light. Hank started to realize 
there were little creatures showing up. They were small and snail like and had varying
expressions on their faces. Hank had read about these creatures before and soon realized they were
the PERIWINKLES OF PERIL! Help hank defend his home by throwing ink at the Perilful Winlkes!

### Classes
* Octopus -- Hank
* Periwinkels of Peril 
* Ink
* Player (for scoring)

### Concept of Game
Periwinkles are invading the personal space of Hank the octopus 
and he shoots his Ink at them to make them die/ find somehwere else to live. 
Hank can move from side to side and the periwinkels fall down towards him. If a periwinkle reaches the 
sea bottom the game is over and hank must find a new place to live. 

### Team Members 
* Zach Bernstein 
* Cecily Page
* Megan Doyle 
* Hunter Jensen

### Graphics Engine
The graphics engine (all files in the `engine/` folder) were created for Final Project 1,
and thus were authored by Ethan Nerney, Jeremy Weiland, Zach Bernstein, and 

### what do do....
Object of the game is to ink the most of the perriwinkles.
The perriwinkes will move down exactly the height of 1 perriwink at a set fun rate.
The more perriwinkes you ink, the drop rate will increase and get faster.

### Scores
For each wink you ink you gain one point. 

The best 3 scores are kept and displayed at the end. If you beat any of the
scores on the board enter your name to be on the score board. 

# Polymorphism
Polymorphism is deployed with the periwinkles. There are three subclasses of periwinkle:
* SmileWinkle
* FrowWinkle
* Awinkle

These winkles are added to an array at random and then all drawn by calling 
(the index in the vector).draw. 

# Impressiveness 
##### Bubbles
Bubbles are floating around in the background because we are under water and there 
are bubbles underwater
##### Mouse
The mouse diapers so you can't just point to the winkle you want to ink. 
This makes the game more challenging.  
##### Winkle Drop Rate
The winkles start dropping faster and closer together the farther along in the 
game you get. 
##### Scores
After each game, the top three scores are displayed and there's a blank text box.
If you feel so inclined, you can put your name into the box and if you beat anyone on
the score board you will appear on the board after hitting enter.

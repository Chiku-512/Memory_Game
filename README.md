# Memory_Game
A real life memory game simulator using 4 LEDs, Red, Blue, Green, Yellow such that random sequences are generated and stored in a memory for the user to match that sequence in memory.
# Circuit_Logic
4 push buttons of red, blue, yellow, green colours read the INPUT response from the user. 4 leds of the corresponding colours are set to OUTPUT for the computer to show the sequence of memory to the player and also to validate the response of the user that he inputs that color of which he clicks the button. An active buzzer is also present to produce sound when player enters a response.
# Code_Logic
For level n, computer blinks n(n+1)/2 leds, of which the first (n-1)n/2 led data comes from the stored memory and the rest n new sequence of leds glow.
Computer first blinks the memory sequence, for the corresponding level and after that asks response from the user.
The sequences are generated randomly by the computer and for each sequence created, it is added to the memory. 
Random sequences are created due to random seed values from the open circuit Analog pin A0.
If the sequence provided by the player (in another answer variable), matches the memory sequence he passes that level, otherwise Serial monitor displays Game Over with the final Score and Game stops.


https://github.com/user-attachments/assets/5c2410a6-36bc-4a14-87f7-87c67202b689




#include <stdio.h>          // We don't need another library for this game.

struct player {             // First we create "player" structure for contain player's info.
    char name[8];
    int score;
    int move;
    char symbol;
};

void main(){
    
    char area[9] = "123456789";                 // For gameboard.
    int mode_answer=0 ,final_answer, draw_score = 0, result = 0, loop_times = 0, loop_of_program = 0, loop_of_menu = 0, loop_of_game = 0, control_of_empty = 0;     // We use all of this for loops except "draw_score".    
    struct player player1, player2, turn;       // We have 2 player and turn (for loops).

    player1.symbol = 'x';                       
    player2.symbol = 'o';
    
    while(loop_of_program == 0){                // This loop for back to start.

        draw_score = 0;
        
        while(loop_of_menu == 0){               // This loop for Menu.

            printf("+++++++++++++++++++++++++++++\n++++++++ Tic Tac Toe ++++++++\n+++++++++++++++++++++++++++++\n\n");

            printf("Please select game mode\n\n1: Against Computer\n2: Against Second Player\n0: Exit Game \n\nAnswer:");
            scanf("%d", &mode_answer);

            switch (mode_answer){               // We show options and orient to right place for selection.
            
            case 1:
                
                printf("\n\nEnter Player 1 Nick: (8 character)\n");
                scanf("%s", player1.name);
                
                loop_of_menu = 1;
                break;

            case 2:

                printf("\n\nEnter Player 1 Nick: (8 character)\n");
                scanf("%s", player1.name);

                printf("\n\nEnter Player 2 Nick: (8 character)\n");
                scanf("%s", player2.name);

                loop_of_menu = 1;
                break;

            case 0:
                goto Exit;
                break;

            default:
                printf("\n\n\n\nPlease select some mode.\n\n");

                loop_of_menu = 0;
                break;
            }

        }

        printf("\n\n%s is 'x'     %s is 'o'\n\n\n", player1.name, player2.name);
        
        player1.score = 0;      // Set 0 for beginning.
        player2.score = 0;
        loop_of_game = 0;

        if(mode_answer == 2){   // If user select 2 player mode he will came there.
        
            while(loop_of_game == 0){  // This loop for game restart.

            char area[9] = "123456789";
            loop_times = 0;
            result=0;

            while(result == 0){         // İf user enter unaccepted character will came back there.
                
                // We print gameboard.
                printf("\n\n\n %c | %c | %c \n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n\n\n", area[6], area[7] , area[8], area[3], area[4], area[5], area[0], area[1], area[2]);

                // Control winning conditions.
                if (((area[0] == area[3]) && (area[3] == area[6])) || ((area[1] == area[4]) && (area[4] == area[7])) || ((area[2] == area[5]) && (area[5] == area[8])) ||   // Control columns.
                    ((area[0] == area[1]) && (area[1] == area[2])) || ((area[3] == area[4]) && (area[4] == area[5])) || ((area[6] == area[7]) && (area[7] == area[8])) ||   // Control raws.
                    ((area[0] == area[4]) && (area[4] == area[8])) || ((area[2] == area[4]) && (area[4] == area[6]))){                                                      // Control diagonal.

                    printf("%s WIN.\n\n\n", turn.name);

                    if (loop_times%2 == 0)
                        player2.score ++;
                    else 
                        player1.score ++;

                    result = 1;

                } else if(loop_times > 8){      // If we can't find out winner for 9 turn thats mean game is draw.

                    printf("We don't have winner. DRAW.\n");
                    draw_score++;
                    result = 1;

                } else {                        // When we have not winner game go on.

                    if (loop_times%2 == 0)
                        turn = player1;
                    else 
                        turn = player2;


                    printf("%s's turn now.\n", turn.name);

                    printf("Please select area for move: ");
                    scanf("%d", &turn.move);

                    // Control there entered move.
                    if(turn.move < 1 || turn.move > 9){
                        printf("\nYou select wrong answer\nPlease select area [1-9].\n\n\n");
                    } else if(area[turn.move-1] == 'x' || area[turn.move-1] == 'o'){
                        printf("\nYou select wrong answer\nPlease select empty area.\n\n\n");
                    } else {
                        area[turn.move-1] = turn.symbol;
                        loop_times ++;
                    }

                }

            }

            // If game is over program print results and next operations menu.
            while(result == 1){
                printf("Score:\n\n%s: %d\n%s: %d\nDraw: %d\n\n1: Play same mode again.\n2: Menu.\n\nAnswer: ", player1.name, player1.score, player2.name, player2.score, draw_score);
                scanf("%d", &final_answer);

                switch (final_answer){
                
                case 1:
                    loop_of_game = 0;
                    result = 0;
                    break;

                case 2:
                    loop_of_program = 0;
                    loop_of_game = 1;
                    loop_of_menu = 0;
                    result = 0;
                    break;

                default:
                    printf("Please select correct answer.");
                    result = 1;
                    break;
                }
            }
        }

        } else{         // If user select against Computer mode he will came there.

            while(loop_of_game == 0){

            char area[9] = "123456789";
            loop_times = 0;
            result=0;
            
            


            while(result == 0){         // İf user enter unaccepted character will came back there.
                
                // We print gameboard.
                printf("\n\n\n %c | %c | %c \n-----------\n %c | %c | %c \n-----------\n %c | %c | %c \n\n\n", area[6], area[7] , area[8], area[3], area[4], area[5], area[0], area[1], area[2]);

                // Control winning conditions.
                if (((area[0] == area[3]) && (area[3] == area[6])) || ((area[1] == area[4]) && (area[4] == area[7])) || ((area[2] == area[5]) && (area[5] == area[8])) ||   // Control columns.
                    ((area[0] == area[1]) && (area[1] == area[2])) || ((area[3] == area[4]) && (area[4] == area[5])) || ((area[6] == area[7]) && (area[7] == area[8])) ||   // Control raws.
                    ((area[0] == area[4]) && (area[4] == area[8])) || ((area[2] == area[4]) && (area[4] == area[6]))){                                                      // Control diagonal.

                    if (loop_times%2 == 0){
                        player2.score ++;
                        printf("Computer WIN.\n\n\n");
                    }else {
                        player1.score ++;
                        printf("%s WIN.\n\n\n", turn.name);
                    }
                    result = 1;

                } else if(loop_times > 8){           // If we can't find out winner for 9 turn thats mean game is draw.

                    printf("We don't have winner. DRAW.\n");
                    draw_score++;
                    result = 1;

                } else {                            // When we have no winner game go on.

                    if (loop_times%2 == 0)
                        turn = player1;
                    else 
                        turn = player2;


                    printf("Your turn now.\n");

                    if(loop_times%2 == 0){              // If users turn we take move from user. 
                        printf("Please select area for move: ");
                        scanf("%d", &turn.move);
                    } else {                            // If Computer turn we calculate next move above. 

                        if ((area[4] == '5') && (((area[1] == area[7]) && (area[7] == 'o')) || ((area[3] == area[5]) && (area[5] == 'o')) || ((area[2] == area[6]) && (area[6] == 'o')) || ((area[0] == area[8]) && (area[8] == 'o')))){
                            turn.move = 5;  
                        } else if ((area[0] == '1') && (((area[3] == area[6]) && (area[6] == 'o')) || ((area[1] == area[2]) && (area[2] == 'o')) || ((area[4] == area[8]) && (area[8] == 'o')))){
                            turn.move = 1;
                        } else if ((area[2] == '3') && (((area[0] == area[1]) && (area[1] == 'o')) || ((area[5] == area[8]) && (area[8] == 'o')) || ((area[4] == area[6]) && (area[6] == 'o')))){
                            turn.move = 3;
                        } else if ((area[6] == '7') && (((area[0] == area[3]) && (area[3] == 'o')) || ((area[7] == area[8]) && (area[8] == 'o')) || ((area[2] == area[4]) && (area[4] == 'o')))){
                            turn.move = 7;
                        } else if ((area[8] == '9') && (((area[6] == area[7]) && (area[7] == 'o')) || ((area[2] == area[5]) && (area[5] == 'o')) || ((area[0] == area[4]) && (area[4] == 'o')))){
                            turn.move = 9;
                        } else if ((area[1] == '2') && (((area[0] == area[2]) && (area[2] == 'o')) || ((area[4] == area[7]) && (area[7] == 'o')))){
                            turn.move = 2;
                        } else if ((area[3] == '4') && (((area[0] == area[6]) && (area[6] == 'o')) || ((area[4] == area[5]) && (area[5] == 'o')))){
                            turn.move = 4;
                        } else if ((area[5] == '6') && (((area[3] == area[4]) && (area[4] == 'o')) || ((area[2] == area[8]) && (area[8] == 'o')))){
                            turn.move = 6;
                        } else if ((area[7] == '8') && (((area[6] == area[8]) && (area[8] == 'o')) || ((area[1] == area[4]) && (area[4] == 'o')))){
                            turn.move = 8;
                        } else if (area[4] == '5' && (area[1] == area[7] || area[3] == area[5] || area[2] == area[6] || area[0] == area[8])){
                            turn.move = 5;
                        } else if (area[0] == '1' && (area[3] == area[6] || area[1] == area[2] || area[4] == area[8])){
                            turn.move = 1;
                        } else if (area[2] == '3' && (area[0] == area[1] || area[5] == area[8] || area[4] == area[6])){
                            turn.move = 3;
                        } else if (area[6] == '7' && (area[0] == area[3] || area[7] == area[8] || area[2] == area[4])){
                            turn.move = 7;
                        } else if (area[8] == '9' && (area[6] == area[7] || area[2] == area[5] || area[0] == area[4])){
                            turn.move = 9;
                        } else if (area[1] == '2' && (area[0] == area[2] || area[4] == area[7])){
                            turn.move = 2;
                        } else if (area[3] == '4' && (area[0] == area[6] || area[4] == area[5])){
                            turn.move = 4;
                        } else if (area[5] == '6' && (area[3] == area[4] || area[2] == area[8])){
                            turn.move = 6;
                        } else if (area[7] == '8' && (area[6] == area[8] || area[1] == area[4])){
                            turn.move = 8;
                        } else if (loop_times == 1){
                            if(area[4] == 'x'){
                                turn.move = 1;
                            } else {
                                turn.move = 5;
                            }
                        } else if (loop_times == 3 || loop_times == 5 || loop_times == 7){
                            if(area[4] == 'o'){
                                if ((area[3]==area[5]) || (area[1]==area[7])){
                                    turn.move = 1;
                                } else if (area[0] == '1' && area[1] == 'x' && area[3] == 'x'){
                                    turn.move = 1;
                                } else if (area[2] == '3' && area[1] == 'x' && area[5] == 'x'){
                                    turn.move = 3;
                                } else if (area[8] == '9' && area[5] == 'x' && area[7] == 'x'){
                                    turn.move = 9;
                                } else if (area[6] == '7' && area[3] == 'x' && area[7] == 'x'){
                                    turn.move = 7;
                                } else if (area[1] == '2'){
                                    turn.move = 2;
                                } else if (area[3] == '4'){
                                    turn.move = 4;
                                } else if (area[5] == '6'){
                                    turn.move = 6;
                                } else {
                                    turn.move = 8;
                                }
                            } else if (area[4] == 'x'){
                                if (area[8] = 'x'){
                                    turn.move = 3;
                                }
                            }
                        }

                            
                        
                    }

                    
                    // Control there entered move.
                    if(turn.move < 1 || turn.move > 9){
                        printf("\nYou select wrong answer\nPlease select area [1-9].\n\n\n");
                    } else if(area[turn.move-1] == 'x' || area[turn.move-1] == 'o'){
                        printf("\nYou select wrong answer\nPlease select empty area.\n\n\n");
                    } else {
                        area[turn.move-1] = turn.symbol;
                        loop_times ++;
                    }

                }

            }

            // If game is over program print results and next operations menu.
            while(result == 1){
                printf("Score:\n\n%s: %d\nComputer: %d\nDraw: %d\n\n1: Play same mode again.\n2: Menu.\n\nAnswer: ", player1.name, player1.score, player2.score, draw_score);
                scanf("%d", &final_answer);

                switch (final_answer){
                
                case 1:
                    loop_of_game = 0;
                    result = 0;
                    break;

                case 2:
                    loop_of_program = 0;
                    loop_of_game = 1;
                    loop_of_menu = 0;
                    result = 0;
                    break;

                default:
                    printf("Please select correct answer.");
                    result = 1;
                    break;
                }
            }
        }
        
        }
    }

    Exit:

    printf("Thanks for playing.\n\n");
      
}

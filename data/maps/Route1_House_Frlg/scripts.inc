Route1_House_Frlg_MapScripts::
	.byte 0

/* Custom scripts start here, leave the mapscripts call about alone */

Route1_House_EventScript_Arter::
	lockall
	faceplayer
	checktrainerflag TRAINER_CAMPER_ARTER
	goto_if 0, Route1_House_EventScript_Arter_2
Route1_House_EventScript_Arter_1:
Continue_Label:
	msgbox Route1_House_EventScript_Arter_Text_2, MSGBOX_AUTOCLOSE
	setflag VAR_ROUTE1_HOUSE_BACKDOOR_LOCK
	releaseall
	return

Route1_House_EventScript_Arter_2:
	trainerbattle_single TRAINER_CAMPER_ARTER, Route1_House_EventScript_Arter_Text_0, Route1_House_EventScript_Arter_Text_1, Continue_Label
	goto Route1_House_EventScript_Arter_1


Route1_Backdoor_EventScript_IsLocked_Pushback::
	goto_if_unset VAR_ROUTE1_HOUSE_BACKDOOR_LOCK, Route1_Backdoor_EventScript_IsLocked_Pushback_2
Route1_Backdoor_EventScript_IsLocked_Pushback_1:
	releaseall
	return

Route1_Backdoor_EventScript_IsLocked_Pushback_2:
	lockall
	faceplayer
	msgbox Route1_Backdoor_EventScript_IsLocked_Pushback_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Route1_Backdoor_EventScript_IsLocked_Pushback_Movement_0
	waitmovement 0
	goto Route1_Backdoor_EventScript_IsLocked_Pushback_1


Route1_Fridge_With_Lemonade::
	lockall
	faceplayer
	goto_if_set VAR_ROUTE1_HOUSE_BACKDOOR_LOCK, Route1_Fridge_With_Lemonade_3
Route1_Fridge_With_Lemonade_1:
	msgbox Route1_Fridge_With_Lemonade_Text_1, MSGBOX_AUTOCLOSE
	releaseall
	return

Route1_Fridge_With_Lemonade_2:
	checkitemspace ITEM_LEMONADE, 1
	compare VAR_RESULT, FALSE
	goto_if_eq Route1_Fridge_With_Lemonade_6
	giveitem ITEM_LEMONADE, 1
	setflag FLAG_HIDE_ROUTE1_HOUSE_ITEM
	releaseall
	end

Route1_Fridge_With_Lemonade_3:
	goto_if_unset FLAG_HIDE_ROUTE1_HOUSE_ITEM, Route1_Fridge_With_Lemonade_2
	goto Route1_Fridge_With_Lemonade_1

Route1_Fridge_With_Lemonade_6:
	msgbox Route1_Fridge_With_Lemonade_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	end


Route1_Backdoor_EventScript_IsLocked_Pushback_Movement_0:
	walk_left
	face_down
	step_end

Route1_House_EventScript_Arter_Text_0:
	.string "Hiya! I've volunteered to help \n Erika by watching this Route.$"

Route1_House_EventScript_Arter_Text_1:
	.string "Keep your eyes peeled, the \n grass outside is filled with \l snakes!$"

Route1_House_EventScript_Arter_Text_2:
	.string "That was quite something.  Feel \n free to take a drink for the \l road.  I'll also make sure the \l back door is unlocked for you.$"

Route1_Backdoor_EventScript_IsLocked_Pushback_Text_0:
	.string "The door is locked.$"

Route1_Fridge_With_Lemonade_Text_0:
	.string "You don't have any room for a \n Lemonade...$"

Route1_Fridge_With_Lemonade_Text_1:
	.string "It's filled with drinks and Eggs \n labeled 'Caterpie'.$"




/* Poryscript container

script Route1_House_EventScript_Arter{
	lockall
    faceplayer
    if (!defeated(TRAINER_CAMPER_ARTER)){
    	trainerbattle_single(	TRAINER_CAMPER_ARTER, 
        						
                                "Hiya! I've volunteered to help \n
								Erika by watching this Route.",
                                
                                "Keep your eyes peeled, the \n
								grass outside is filled with \l
								snakes!"		,
                                
                                Continue_Label)}

    Continue_Label:
    msgbox (	"That was quite something.  Feel \n
				free to take a drink for the \l
				road.  I'll also make sure the \l
				back door is unlocked for you.",
                    
                MSGBOX_AUTOCLOSE)
    setflag(VAR_ROUTE1_HOUSE_BACKDOOR_LOCK)
	releaseall}
    
    
script Route1_Backdoor_EventScript_IsLocked_Pushback{
if (!flag(VAR_ROUTE1_HOUSE_BACKDOOR_LOCK)){
    	lockall
        faceplayer
		msgbox ("The door is locked.", MSGBOX_AUTOCLOSE)
        applymovement (OBJ_EVENT_ID_PLAYER, moves(walk_left face_down))
        waitmovement(0)}
releaseall
}

script Route1_Fridge_With_Lemonade{
lockall
faceplayer

if (flag(VAR_ROUTE1_HOUSE_BACKDOOR_LOCK) && !flag(FLAG_HIDE_ROUTE1_HOUSE_ITEM)){
		if (checkitemspace (ITEM_LEMONADE, 1) == FALSE) {
        	msgbox ("You don't have any room for a \n
					Lemonade...",
                    
					MSGBOX_AUTOCLOSE)
            releaseall end}
        else { giveitem (ITEM_LEMONADE, 1)
        	   setflag (FLAG_HIDE_ROUTE1_HOUSE_ITEM)
               releaseall end}
        }

msgbox ( 	"It's filled with drinks and Eggs \n
			labeled 'Caterpie'.",
            
            MSGBOX_AUTOCLOSE)
releaseall
}
           

*/
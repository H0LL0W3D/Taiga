#include <string>



//PSUEDO CODE FOR PLAYER OR CHARACTER ATTRIBUTES


class CharacterController{
	//controls non-player character factors
}



class Item{
}


class Character{
}



class Condition{
}


class Faction{
}



/*

Character:
There should be 4 different factions of character. Our current ideas are: Civilian, Orthodox clergy, Train crew , and (?) 


A character has basic needs and a personality matrix that determines activity.
A character will take care of their needs when untasked (or tasked to rest). 
A character with positive needs will be in good spirits.
A character with negative needs will be in bad spirits.
A character in good spirits will generally be more productive, and inspire others.
A character in bad spirits will be less productive, draining to others, and possibly go mad.
Odds of a character going mad increase if there are conflicting artifact effects

Madness: A character that has gone mad will refuse all orders, and do one of the following (based on personality).
Attack other characters - highest violence, outward
Attempt to commit suicide - highest violence, self-destructive
Start a fire on a building or stockpile - high violence, outward
Attack buildings or resources - medium violence, outward
Verbally abuse others, decreasing their moods - low violence, outward
Put out all the campfires and sources of warmth it can find - not violent, outward
Wander away and get lost. - not violent, self-destructive
Sleep for a very long time - not violent, not destructive
Madness will last a random amount of time, but should be long enough to cause trouble or kill the character. A character that has previously gone mad and survived will either have increased odds of going mad again, or much greater resistance to it (depending on personality).

Character Needs
Hunger - a character needs to eat a particular amount every turn to be fully satisfied. Eating a meal suited for its diet type will satisfy more hunger. Eating a food not suited may cause the character to get sick and increase hunger even more. Improved meals will fully satisfy and also increase mood. Failing to fully satisfy on each turn will gradually increase hunger need, which decreased mood and productivity. Satisfying hunger for a certain amount of turns will end this effect. Eating spoiled food will cause sickness, and increase hunger dramatically. 

Rest - a character must rest for at least 1 turn per day. Failing to do so will build up fatigue quickly, reducing a character’s mood/productivity and increasing chances of madness. A fatigued character will require several turns of rest to recover. Wounds also need rest to heal properly. A wounded character who does not rest will not recover.
Socialization - This depends on the character’s personality, but generally involves relaxing and or socializing with other characters. Teaming up characters with friends will satisfy this need while they work. Otherwise, they will attempt to satisfy it during a rest turn or an turn without orders. 

Character Personality
Character personalities are made up of slots that are randomly filled. 
Archetypes define the major personality of a character. Archetypes may be multiplied by a magnitude, but this takes up a lesser trait slot to do so. 

Archetype - Major Personality Trait (1 slot only)
Barbaric - Very effective in combat (higher atk, defense). Poor crafting skills. Increases odds of making enemies. Increases odds of outwardly violent acts during madness. 

Intellectual - Very effective at crafting tasks. Poor combat effectiveness. Decreases odds of making friends but does not make enemies either. Madness is often self-destructive.

Hard Working - Very effective at building and hauling tasks. Average at craft and combat. Increases odds of making friends. Madness is a chaotic grab-bag of anything. 

Lesser Traits - Minor Personality Traits (3 slots)
Archetype Multiply - Increases the effects of the archetype, but takes up a trait slot to do so.
Describes as “very [archetype]”. Slot for trait is left blank at bottom. Can stack.

Socialite - Increases magnitude of social interaction effects. For intellectuals, this enables the character to make good friends but good enemies too. 

Introvert - No stress increase from being alone- inversely, stress increases near groups of people who are at neutral or less.

Resilient - Greatly reduces odds of going mad again after the character goes mad.

Dreamer - Increases odds of going mad, but reduces likelihood of the madness being violent.

Marksman - Increases performance with bow and arrow or thrown spear. Reduces performance with melee weapons.

Fighter - Increases performance with melee weapons. Reduces ranged weapon performance.

Xenophobic - Increases effect of positive socialization on same species, and negative socialization on other species. 

Tireless - reduces number of additional rest turns needed to recover from exhaustion.

Frugal - increases rate of hunger satisfaction, and lessens hunger growth

Iron Stomach - greatly decreases odds of getting sick from bad/wrong food

Fearless - Not stressed much by hunger, cold, or tiredness.

Indestructible - Heals much faster. Has a slim chance of not taking any damage on an attack.

Hot Blooded - Reduces temperature decrease rate.

Hasty - Increases work and movement speed

Charming - Increases odds that other characters will like this one

Bloodthirsty - Fighting will greatly reduce stress. Effect is stronger when fighting a very-disliked character. Higher chances that a fight will result in the death of the victim if it is a colony member.

Pacifist - Will not fight any characters that belong to the colony. 

Calm - Stress levels increase much slower, and decrease much faster. 

Craftsman - No stress when performing a craft task

Layman - No stress when performing a haul/build task

Explorer - Decreases stress slightly when exploring a new tile. No stress from being away.
Character Status

Character status are determined by fuzzy logic. A state will have an external “value” marker that determines end behavior, but each state has an internal tracker that allows partial progress towards the next stage. States range from 5 being the best to 0 being the worst. 
Hunger
Decreases slightly every turn. Increased by food quality amount when eating.
Starvation is reached at 1. Death will occur at 0.
5- Satisfied - no hunger. Reduces stress levels slightly.
4- Peckish - slight hunger. No negative effects, but notifies the character needs to eat.
3- Hungry - No negative physical effects, but stress is increased
2- Very Hungry - Physical work ability decreased. Fatigue increases. Bad stress.
1- Starving - Physical work greatly decreased. Exhaustion level fatigue. Terrible stress.
0- Death - Character starves to death.

Internal Parameters of Hunger:
    Work Rate - hunger is increased slightly when performing tasks
    Rest Rate - hunger is increased less when spending a turn to rest
    Sickness Chance - eating wrong/bad food can cause immediate sickness (vomiting) and
        drop the hunger level. Cannot drop below 1 due to sickness.
        Getting sick greatly increases stress and fatigue.

Hunger Rate curve 
Image
t is time in turns.   h is hunger rating.
Generates a curve that is y roughly equals 5 at x=0, and y = 0 at x = 60. Sharp decline in hunger, but slowly declines to 0 after a long time, so that character is starving for several days before death.

(note e = 2.71828128459045)

The hunger curve provides a base value for what hunger should be at for time t. It does not account for fatigue and character archetype hunger rate- which is processed for a “total” value that does not directly affect the curve. 
Fatigue
Increases by a small amount each turn. Increases more for hard work or when hungry.
Exhaustion occurs when the character does not rest or is overworked for a period of time.
Rest will eliminate any fatigue below “exhausted”. Exhaustion requires multiple turns of rest to recover, based on how exhausted the character is. 
5- Rested - not tired. Normal performance. Reduces stress impact.
4- Worked - somewhat tired. Normal performance. No change in stress impact.
3- Tired - Slightly reduced performance. Increased stress impacts.
2- Exhausted - greatly reduced performance. Increased impact of stress.
1- Very exhausted - no work performance. Slow movement. Very negative stress impact. 
0- Pass out - character passes out and is forced to rest where it is. May freeze to death.

Internal parameters of Fatigue
    Hunger Impact - increases fatigue when hunger is less than 2. Immediately drops to 
        “Exhausted” level if hunger is 1. Cannot recover from “exhausted” until hunger is
        restored. 
    Work Impact - fatigue is increased slightly by performing tasks.
    Wound Impact - having wounds increases fatigue slightly. 
Stress
Stress is increased over time due to work. It is increased more when hungry and tired. Full rest will reduce stress slightly, but not enough to counteract busy work days. Negative interactions will increase stress. Positive interactions will reduce stress- and likewise, high stress will induce more negative interactions, and low stress will induce positive interactions. Spending time awake but untasked will reduce stress. Working with a friend will reduce stress increase rate. Stressed characters will be more likely to have negative interactions with others and may start small fights (depending on personality). Stressed characters have a high chance of going mad. Stressed characters may also refuse an order. Stressed characters being around other stressed characters will slightly increase stress rate, and vice versa.

5 - Carefree - not stressed. Positive morale boost.
4 -Focused - slightly stressed. No morale boost.
3 -Flustered - somewhat stressed. 
2 -Tense - stressed. Likely to cause negative interactions.
1 -Nervous Wreck - very stressed. Likely to start fights or refuse orders.
0 -Insane - Character goes mad. 

Internal parameters of stress:
    Impact Rate - magnitude multiplier of negative stress events. Any effect that attempts to
        increase stress is multiplied by this rate.

Warmth
Warmth is determined by the weather and if the character is wearing good clothing. Characters inside will not lose warmth, whereas characters outside will lose warmth gradually. Being near a fire will restore warmth by 1 rank per turn. Cold characters work slower and have increased stress. Freezing characters work very slow and have high stress. A character will freeze to death if its temperature gets too low. 

5 - Cozy - no cold penalties and slight reduction of stress impact.
4 - Neutral - no cold penalties but no mood boost
3 - Chilly - no cold penalties but slight stress increase
2- Cold - slight cold penalties and stress increase
1- Freezing - large cold penalty and stress increase
0 - Death - character freezes to death.

Internal Parameters of Warmth
    Clothing Score - reduces temperature loss per turn by the clothing rating.
    Weather Score- determines base temperature loss rate per turn while outside.
Stress Events
Events that will affect stress. These rates effect per turn when applicable.

Death of a strange beast - lowers stress
Making a new friend - lowers stress
Positive social interaction with friend - lowers stress
Positive social interaction with others - lowers stress slightly
Untasked turn while awake - lowers stress slightly
Extra turn of rest while not exhausted - lowers stress slightly
Eating improved meal - lowers stress slightly
Being cozy warm - lowers stress very slightly

Being treated at infirmary for wound - removes stress from wound
Taking medicine for wound - decreases wound stress impact for being untreated
Being tired - affects stress impact rate for negative events

Working a task with a friend - very slight stress increase
Working a task alone or with neutral party - very slight stress increase
Working a task with a disliked person - slight stress increase
Being cold - stress increase based on level of cold
Being hungry - stress increase based on level of hunger
Having a wound - stress increases slightly per untreated and unhealed wound.
Being away from the colony - slight increase, based on distance (except for explorer trait)
Being alone during a turn - slight increase (except for those with introvert trait)
Witnessing a strange beast - slight increase
Being attacked by a colony member - increase stress
Witnessing a building on fire - increase stress
Being wounded - increase stress
Loss of another person - increase stress
Witnessing the loss of another person - increase stress
Loss of a friend - high stress increase
Witnessing the loss of a friend - very high stress increase

*/




int() main{


	return 0;
}
#include <string>


//PSUEDO CODE FOR WORLD BUILDING / MAINTAINING / UTILIZING


class WorldController{
	//controls non-player world factors


}


class World{
	//for organization of world
protected:
	Tile alpha; //constant size world
	//functions of time. Use with an existing library?
	time;
	season;
	Light;
	precipitation;




}


class Building{
	//for buildings

protected:
	int HP;
	int flammable;
	bool accessible;
	Task alpha;
	Task beta;
	Item[] Storage;	//probably uses this datatype from somewhere else
	??? owner;	//idk wtf datatype we use here
	Temperature internalTemp;	//unsure what datatype we using for this yet




}




class Tile{
	//individual units of the map

	Resource alpha;
	Resource beta;
	Resource delta;
	Building gamma;
	//Temperature temperature; //unsure how this should be handled


}




class Resource{
	//individual resource. Quantity, bool check, sets and gets
	protected:
		string name;
		int quantity;
		int type;
		int renewRate;
		int gatherRate;
		//bool isPresent;	//may not be necessary?


		//set
		public void setQuantity(int newQuantity){ quantity = newQuantity; }
		public void setName(string newName){ name = newName; }
		public void setType(int newType){ type = newType; }
		public void setRenewRate(int newRenewRate){  renewRate = newRenewRate; }
		public void setGatherRate(int newGatherRate){ gatherRate = newGatherRate; }
		//public void setPresent(bool appear){ isPresent = appear; }

		//get
		public int getQuantity(){ return quantity; }
		public string getName(){ return name; }
		public int getType(){ return type; }
		public int getRenewRate(){ return renewRate; }
		public int getGatherRate(){ return gatherRate; }
		//public bool getPresent(){ return isPresent; }

}


/*
“2 inches an hour is a significant amount”
“2 inches an hour is a typical blizzard/whiteout rate”
“Seen up to 6 inches an hour before”

3 days at 50 degrees will melt 3 inches
It can be assumed 1 day at 50 degrees will melt about 1 inch
To get a rate, compare 1 day at 32 will melt 0
The slope is 50-32, or 18 degrees per inch per day

Per hour, this becomes:
1 day = 24 hours
1 inch per 24
1/24th of an inch per hour per 18 degrees above 32
1/24 is .0417

X is temperature
f(x) is snow melted per hour

f(x) = .0417 * ((x - 32) / 18)

X is temperature
T is hours
f(x, t) = t * (.0417 *  ((x - 32) / 18)

Test: Expected result is 3
f(50, 72) = 72 * (.0417 * ((50 - 32) / 18)
          72 * (.0417 * ((18)/18)
          72 * (.0417 * 1)
          72 * .0417
          3.002


Snowfall Rate
f(x, r, t) = x * r * t
Where x is precip level, r is rate, and t is hours

Easy: R is .125
.5 inches per turn (.125 inches per hour)
1 inch per turn (.25 inches per hour)
1.5 inches per turn (.375 inches per hour)

Hard: R is .5
2 inch per turn (.5 inches per hour)
4 inches per turn (1 inches per hour)
6 inches per turn (1.5 inches per hour)

Nightmare: R is .75
3 inches per turn (.75 inches per hour)
6 inches per turn (1.5 inch per hour)
9 inches per turn (2.25 inches per hour)




*/


int() main{


	return 0;
}

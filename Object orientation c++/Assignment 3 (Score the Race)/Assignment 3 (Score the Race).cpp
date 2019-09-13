//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

using namespace std;

int main()
{
	string userInput;
	map<char, float>umap;
	map<char, float>::iterator it;
	set<char> uset;
	int teamMembers = 0;
	while(true)
	{
	    cout<< "Enter the result\n";
		cin >> userInput;
		if (userInput == "done")
			 break;

		for (int i=0; i<userInput.size(); i++)
			umap[userInput[i]] += (i+1);

		//for (auto x : umap){
		//	teamMembers = count(userInput.begin(), userInput.end(), (char)x.first);
		//	uset.insert(teamMembers);
		//}
		for (it = umap.begin(); it!=umap.end(); it++){
			teamMembers = count(userInput.begin(), userInput.end(), (char)it->first);
			uset.insert(teamMembers);
		}


		// check if the total number of members are different in each team
		if (uset.size() ==  1)
			cout << "There are " << umap.size() << " teams." << endl;
		else{
			cout << "Members are not equal in all teams." << endl;
			break;
		}
		// end

		float winner_score = umap.begin()->second/teamMembers;
		char winning_team;
		cout << "Each team has " << teamMembers << " members." << endl;
		cout << "Team  Score" << endl;
		cout << "----  -----" << endl;
		for (it = umap.begin(); it!=umap.end(); it++){
			float score = it->second/teamMembers;
			if (score <= winner_score){
				winner_score = score;
				winning_team = (char)it->first;
			}
			cout << it->first << "     " << score << endl;
		}
		cout << "The winning team is team " << winning_team << "  with a score of " << winner_score << "."<< endl;
	}
}










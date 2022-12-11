#include <bits/stdc++.h>
#include <set>

using namespace std;
struct latlong
{
    char dir;
    float degree;
};
struct Wind_Rose
{

    string dir;
    float percent;
};
struct Water_body
{
    string waterbody;
    float distance;
    string Dir;
};
struct Setback
{
    float front, back, left, right;
};
struct Workplace
{
    float cubical, cabin;
    char occupation_stress;
    string workplace_occupation;
};
struct Area
{
    float length, breadth;
};

int directionNSEW(char s)
{
    if (s == 'N')
        return 0;
    else if (s == 'S')
        return 1;
    else if (s == 'E')
        return 2;
    return 3;
}

void order(vector<pair<int, int>> v)
{
    for (int i = 0; i < 4; i++)
    {
        if (v[i].second == 0)
        {
            cout << "NORTH"
                 << " ";
        }
        if (v[i].second == 1)
        {
            cout << "SOUTH"
                 << " ";
        }
        if (v[i].second == 2)
        {
            cout << "EAST"
                 << "  ";
        }
        if (v[i].second == 3)
        {
            cout << "WEST"
                 << "  ";
        }
        cout << v[i].first << endl;
    }
    cout << endl;
}
int main()
{
    // cout << "latitude :  longtitude " << endl;

    struct latlong latitude, longitude;
    cin >> latitude.degree >> latitude.dir;
    cin >> longitude.degree >> longitude.dir;
    cout << latitude.degree << " " << latitude.dir << endl;
    cout << longitude.degree << " " << longitude.dir << endl;

    // cout << "Annual rainfall " << endl;

    float annual_rainfall;
    cin >> annual_rainfall;
    cout << annual_rainfall << endl;

    // cout << "wind_rose : prevailing " << endl;

    struct Wind_Rose prevailing, prevailing_2;
    cin >> prevailing.dir >> prevailing.percent;
    cin >> prevailing_2.dir >> prevailing_2.percent;

    cout << prevailing.dir << " " << prevailing.percent << endl;
    cout << prevailing_2.dir << " " << prevailing_2.percent << endl;

    // cout << "Annual : temp " << endl;

    // float annual_average_temp, annual_average_temp_summer, annual_average_temp_winter;
    // cin >> annual_average_temp >> annual_average_temp_summer >> annual_average_temp_winter;

    // cout << annual_average_temp << " " << annual_average_temp_summer << " " << annual_average_temp_winter << endl;

    // cout << "water body " << endl;

    struct Water_body Nearwater;
    cin >> Nearwater.waterbody >> Nearwater.distance >> Nearwater.Dir;
    cout << Nearwater.waterbody << " " << Nearwater.distance << " " << Nearwater.Dir << endl;

    // cout << "Area" << endl;

    struct Area available_Area;
    cin >> available_Area.length >> available_Area.breadth;
    cout << available_Area.length << " " << available_Area.breadth << endl;

    // cout << "Setback " << endl;

    struct Setback setback;
    cin >> setback.front >> setback.back >> setback.left >> setback.right;
    cout << setback.front << " " << setback.back << " " << setback.left << " " << setback.right << endl;

    // cout << "workplace " << endl;

    struct Workplace work;
    cin >> work.cabin >> work.cubical >> work.workplace_occupation >> work.occupation_stress;
    cout << work.cabin << " " << work.cubical << " " << work.workplace_occupation << " " << work.occupation_stress << endl;

    // cout << "road and neigbouring  " << endl;

    int roadPassby_no, neighboring_infrastructure_no;
    cin >> roadPassby_no;
    string RoadPasArray[roadPassby_no];
    for (int i = 0; i < roadPassby_no; i++)
    {
        cin >> RoadPasArray[i];
    }
    for (int i = 0; i < roadPassby_no; i++)
    {
        cout << RoadPasArray[i] << " ";
    }
    cout << endl;

    cin >> neighboring_infrastructure_no;
    string NeighborArray[neighboring_infrastructure_no];
    for (int i = 0; i < neighboring_infrastructure_no; i++)
    {
        cin >> NeighborArray[i];
    }
    for (int i = 0; i < neighboring_infrastructure_no; i++)
    {
        cout << NeighborArray[i] << " ";
    }
    cout << endl;

    vector<int> windowdirection(4, 0);

    if (latitude.degree >= 45)
    {
        windowdirection[directionNSEW(latitude.dir)] += 5;
    }
    else
    {
        windowdirection[directionNSEW(latitude.dir)] += 3;
    }

    if (Nearwater.waterbody == "Sea" || Nearwater.waterbody == "sea" || Nearwater.waterbody == "Ocean" || Nearwater.waterbody == "ocean")
    {
        if (Nearwater.distance <= 2)
        {
            int len = Nearwater.Dir.size();
            if (len == 1)
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 4;
            else
            {
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 4;
                windowdirection[directionNSEW(Nearwater.Dir[1])] += 4;
            }
        }
        else if (Nearwater.distance >= 2 && Nearwater.distance <= 10)
        {
            int len = Nearwater.Dir.size();
            if (len == 1)
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 3;
            else
            {
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 3;
                windowdirection[directionNSEW(Nearwater.Dir[1])] += 3;
            }
        }
        else if (Nearwater.distance >= 10 && Nearwater.distance <= 15)
        {
            int len = Nearwater.Dir.size();
            if (len == 1)
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 2;
            else
            {
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 2;
                windowdirection[directionNSEW(Nearwater.Dir[1])] += 2;
            }
        }
        else if (Nearwater.distance >= 15 && Nearwater.distance <= 20)
        {
            int len = Nearwater.Dir.size();
            if (len == 1)
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 1;
            else
            {
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 1;
                windowdirection[directionNSEW(Nearwater.Dir[1])] += 1;
            }
        }
    }
    else if (Nearwater.waterbody == "lake" || Nearwater.waterbody == "Lake" || Nearwater.waterbody == "Pond" || Nearwater.waterbody == "pond")
    {
        if (Nearwater.distance <= 0.2)
        {
            int len = Nearwater.Dir.size();
            if (len == 1)
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 5;
            else
            {
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 5;
                windowdirection[directionNSEW(Nearwater.Dir[1])] += 5;
            }
        }
        else if (Nearwater.distance >= 0.2 && Nearwater.distance <= 0.5)
        {
            int len = Nearwater.Dir.size();
            if (len == 1)
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 3;
            else
            {
                windowdirection[directionNSEW(Nearwater.Dir[0])] += 3;
                windowdirection[directionNSEW(Nearwater.Dir[1])] += 3;
            }
        }
    }

    int length1 = prevailing.dir.size();
    int length2 = prevailing_2.dir.size();

    // cout << "Prevailing count " << endl;
    map<char, string> m;
    for (int i = 0; i < length2; i++)
    {
        m[prevailing_2.dir[i]] = "P2";
    }
    for (int i = 0; i < length1; i++)
    {
        m[prevailing.dir[i]] = "P1";
    }

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second == "P1")
        {
            if (prevailing.percent >= 33)
            {
                windowdirection[directionNSEW(it->first)] += 4;
            }
            else if (prevailing.percent >= 12 && prevailing.percent <= 33)
            {
                windowdirection[directionNSEW(it->first)] += 3;
            }
            else if (prevailing.percent >= 7 && prevailing.percent <= 12)
            {
                windowdirection[directionNSEW(it->first)] += 2;
            }
            else if (prevailing.percent >= 4 && prevailing.percent <= 7)
            {
                windowdirection[directionNSEW(it->first)] += 1;
            }
        }
        else if (it->second == "P2")
        {
            if (prevailing_2.percent >= 33)
            {
                windowdirection[directionNSEW(it->first)] += 4;
            }
            else if (prevailing_2.percent >= 12 && prevailing_2.percent <= 33)
            {
                windowdirection[directionNSEW(it->first)] += 3;
            }
            else if (prevailing_2.percent >= 7 && prevailing_2.percent <= 12)
            {
                windowdirection[directionNSEW(it->first)] += 2;
            }
            else if (prevailing_2.percent >= 4 && prevailing_2.percent <= 7)
            {
                windowdirection[directionNSEW(it->first)] += 1;
            }
        }
    }

    // cout << "Windirerection " << endl;
    vector<pair<int, int>> windowprefOrder;
    vector<pair<int, int>> VentilationprefOrder;
    for (int i = 0; i < 4; i++)
    {
        // cout << i << " " << windowdirection[i] << endl;
        windowprefOrder.push_back(make_pair(windowdirection[i], i));
    }
    sort(windowprefOrder.begin(), windowprefOrder.end(), greater<>());
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << windowprefOrder[i].first << " " << windowprefOrder[i].second << endl;
    // }
    cout << endl;

    vector<int> VentilationDir(4, 0);
    for (int i = 0; i < 4; i++)
    {
        VentilationDir[i] = windowdirection[i];
    }

    if (latitude.degree >= 45)
    {
        VentilationDir[directionNSEW(latitude.dir)] = windowdirection[directionNSEW(latitude.dir)] - 5;
    }
    else
    {
        VentilationDir[directionNSEW(latitude.dir)] = windowdirection[directionNSEW(latitude.dir)] - 3;
    }

    for (int i = 0; i < 4; i++)
    {
        // cout << i << " " << VentilationDir[i] << endl;
        VentilationprefOrder.push_back(make_pair(VentilationDir[i], i));
    }
    sort(VentilationprefOrder.begin(), VentilationprefOrder.end(), greater<>());
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << VentilationprefOrder[i].first << " " << VentilationprefOrder[i].second << endl;
    // }

    int flag = -1;
    for (int i = 0; i < 4; i++)
    {
        if (VentilationDir[i] != windowdirection[i])
            flag = 0;
    }
    if (flag == 0)
    {
        cout << "The required preference order for window is : " << endl;
        order(windowprefOrder);
        cout << "The required preference order for Ventilation is : " << endl;
        order(VentilationprefOrder);
    }
    else
    {
        cout << "The required preference order for window and ventlation is : " << endl;
        order(windowprefOrder);
    }

    available_Area.length -= (setback.left + setback.right);
    available_Area.breadth -= (setback.front + setback.back);

    float AvailalbleArea = available_Area.length * available_Area.breadth;
    float ratio = work.cubical / work.cabin;

    cout << "Ratio"
         << " " << ratio << endl;
    float cubicalArea = 3.24, cabinArea = 7.84;

    float p;
    if (work.occupation_stress == 'A')
        p = 0.75;
    if (work.occupation_stress == 'B')
        p = 0.55;
    if (work.occupation_stress == 'C')
        p = 0.40;

    float OptimisedArea = AvailalbleArea * p;

    int NumOfCabins_singlefloor = OptimisedArea / (ratio * cubicalArea + cabinArea);
    int NumOfCubicles_singlefloor = ratio * NumOfCabins_singlefloor;

    int numberoffloor = work.cabin / NumOfCabins_singlefloor + 1;
    if (int(work.cubical / NumOfCubicles_singlefloor) + 1 > numberoffloor)
    {
        numberoffloor = work.cubical / NumOfCubicles_singlefloor + 1;
    }
    cout << NumOfCubicles_singlefloor << " " << NumOfCabins_singlefloor << " " << numberoffloor << endl;
 
    
}
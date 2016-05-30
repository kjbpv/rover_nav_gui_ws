#!/bin/bash 
#chmod a+x ~/gitMars/ros_nav_gui_ws/src/nav_gui/screenshots/initializeMap.sh   #Gives everyone execute permissions

# get path
myPath=$(pwd)
#echo "Here is the current path:"
#echo $myPath

# Select map to use
echo "Please enter the name of the map you would like to use: "
read mapFolder

# copy information for chosen map
echo "Now copying initialization data from" $mapFolder

cp $myPath/$mapFolder/image.png $myPath/image.png
cp $myPath/$mapFolder/waypoints.txt $myPath/waypoints.txt
cp $myPath/$mapFolder/mapInit.txt $myPath/mapInit.txt
cp $myPath/$mapFolder/roverData.txt $myPath/roverData.txt
cp $myPath/$mapFolder/obstacles.txt $myPath/obstacles.txt
cp $myPath/$mapFolder/anchor.txt $myPath/anchor.txt

# create text file containing appropriate arguments for nav_subscriber
#echo $myPath/image.png $myPath/waypoints.txt $myPath/mapInit.txt $myPath/roverData.txt >> myData.txt


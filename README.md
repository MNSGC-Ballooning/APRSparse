# APRSparse
Parses raw APRS data and creates a CSV with only useful data

Instructions:

1. Go to APRS.fi and type in the callsign for your APRS unit.

2. Click on "Raw Packets" link on the menu to the right. This may require you to login or create an account. If you don't have an account, go ahead and sign up. It only takes a couple minutes.

3. You should see a screen with 50 raw packets listed. On the top, you can select how many packets you want to see. List the maximum number of packets, or until you can scroll through and view all the packets from your flight (Look at the time stamps at the beginning of each packet to make sure you have at launch time through land time).

4. Copy all of the packets that you want to parse.

5. Open up your preferred text editor (I prefer notepad) and paste the packets in.

6. Save your file in a folder that specifies which launch this data is for ("GLxxx") and make sure to name the text file "rawAPRS". (THIS IS VERY IMPORTANT AS THE PARSER LOOKS FOR THIS FILE NAME)

7. Place the "APRSparse" application in the same folder as the "rawAPRS" text file, then double click on the application. A CSV file should appear in the folder and it should have the file name "filteredAPRS".

8. Open the file and make sure all of the data is correct. The parsing application does a pretty good job filtering packets for you, but you could get a packet or two that throw everything off. In that case, delete that packet in your text file and re-run it to create a new CSV.

****If you have any questions, email Andrew Van Gerpen at vange055@umn.edu or andrew.vangerpen@gmail.com. Feel free to modify and improve this parser to catch more mischevious packets!!!!!*****

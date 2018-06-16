Bugs that i fixed along the way:
1. after the first menu selection, every proceeding selection would take the same char as the first menu selection. Eventually i found that i had to make use of the clear function in the iostream library.

2. for some reason only my char character for the Style type would take the same value for every book i added. Eventually i found that i had incorrectly used >> incorrectly after the cin.getline

3. After i expanded and contracted my library, when necessary, I would get some sort of errors where my titles and artists would be partially incorrect and my formatting would be off. I eventually found that i had to delete the library pointer and set it equal to the new created pointer rather than setting it equal to the new created pointer then deleting that same pointer

4. Showing size of array was off. At first i was maintaining a variable of the total size within the playlist library. Then i figured I can create a function that goes through and adds all the sizes rather than keeping track of the total storage within member functions that altered it.

5. I couldnt get the IO to ignore any extra characters that the user may have inserted. After consulting with a TA, I was able to create a function that used the iostream library to eat up any extra characters if they existed.

6. I had tons of errors getting the formatting to behave correctly. At first i had them all with the same setw() value but then i realized it varied depending on the size of the title and author string and the number of characters being printed. After working it out on paper i was able to implement the appropriate algorithm for it.

7. I had trouble getting the sort function to work. I had trouble getting the min value to not compare to itself the second way through the loop. I still haven't found a way to fix it.

8. In my sort function for some reason it wouldn't sort the last song in the playlist. I then realized that i had to manually append the last remaining song into the last slot of the sorted library



Bugs that currently exist:

1. If someone inserts a title longer than 35 characters it will leak into the arist name

2. if someone inserts a artist name that has more than 20 characters then it will leak and attempt to insert the 21st character into the Category type

3. if 2 song titles have the same name and the user attempts to sort it, it will glitch and one of the songs will have missing data for some reason

4. in the sort function, since i am using the the remove song function, it may show that the array is being resized when in reality it is not. I did this so that titles wouldnt be compared to itself when going through the library.

5. when sorted by title, it will not sort by author after for some odd reason. can't seem to figure out why.

6. songs with capital letters will always be placed first in sort function since the capital letters come first in the ascii table

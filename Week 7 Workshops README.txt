All Pairs:
The most difficult part was decided where to reset the min value back to max limit.
If done incorrectly, this would prevent the new graph from having the correct outputs.

Format Text:
It was interesting to find out that most doubles and float were compatible with each other, and 
chars and ints were also compatible. It is important to know that a char will output its ascii character
when converted to an int and vice versa.

File Test:
When reading a file, the scan function does not take into account tabs or even new lines; it simply
looks to the next compatible character that is not a space.
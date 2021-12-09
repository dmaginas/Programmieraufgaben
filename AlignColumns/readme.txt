Align columns
TaskAlign columns
You are encouraged to solve this task according to the task description, using any language you may know.
Given a text file of many lines, where fields within a line are delineated by a single 'dollar' character,
write a program that aligns each column of fields by ensuring that words in each column are separated by at
least one space. Further, allow for each word in a column to be either left justified, right justified, or
center justified within its column.


Use the following text to test your programs:

Given$a$text$file$of$many$lines,$where$fields$within$a$line$
are$delineated$by$a$single$'dollar'$character,$write$a$program
that$aligns$each$column$of$fields$by$ensuring$that$words$in$each$
column$are$separated$by$at$least$one$space.
Further,$allow$for$each$word$in$a$column$to$be$either$left$
justified,$right$justified,$or$center$justified$within$its$column.

Note that:

1.  The example input texts lines may, or may not, have trailing dollar characters.
2.  All columns should share the same alignment.
3.  Consecutive space characters produced adjacent to the end of lines are insignificant for the purposes of the task.
4.  Output text will be viewed in a mono-spaced font on a plain text editor or basic terminal.
5.  The minimum space between columns should be computed from the text and not hard-coded.
6.  It is not a requirement to add separating characters between or around columns.
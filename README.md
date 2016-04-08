# ConnectX

NAME : Rahul Shinde

## Bugs:
* BUG 01 : inBounds() returns true value even though value of the width is invalid and value of the height is valid.
* BUG 02 : placePiece() toggles the player even if you provide invalid column to the placePiece().

|  BUG No |      BUG Description      |  Steps to Reproduce  | Actual Result | Expected Result |    Pass/Fail    |
| ------- | ------------------------- | -------------------- | ------------- | --------------- | --------------- |
|   01    | inBounds() returns true   |1. Enter invalid value| Returns True  |  Returns False  |       Fail      |
|         | value even though value   |   of 'w' in at().    |               |                 |                 |
|         | of the width is invalid   |2. Enter valid value  |               |                 |                 |
|         | and value of the height   |   of 'h' in at().    |               |                 |                 |
|         | is valid.                 |                      |               |                 |                 |
|         |                           |                      |               |                 |                 |
|   02    | placePiece() toggles the  |1. Enter valid column | It switches   |  It should stick|       Fail      |
|         | player even if you provide|   value in placePiece| players even  |  with the player|                 |
|         | invalid column to the     |2. Enter invalid col  | if entered    |  who entered    |                 |
|         | placePiece().             |   value.             | invalid col   |  invalid column |                 |
|         |                           |3. Again enter valid  | value.        |  value.         |                 |
|         |                           |   column value.      |               |                 |                 |
|         |                           |                      |               |                 |                 |

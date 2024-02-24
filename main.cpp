const short CShape::m_pStockShapes[] = { 
     11,   // No Of shapes in the array
     2 /*No of orientation shapes */, 4 /*No Of blocks for this shape*/,
     2,1, 2,2, 3,2, 3,3,     //  O
     1,2, 2,2, 2,1, 3,1,     //  OO 
                             //   O 
     0,   // Each shape ends with a 0
}

struct SBlock {
  Short nX,nY,nColor;
};

class CBlockList {
public:
    // Return true if the given location is already occupied
    bool IsOccupied(short nX, short ,nY) ;
    //Inserts the block based on the value in linked list.
    bool Insert(Sblock Block);
    // Adds the block to the end of the list.
    bool Add (const Sblock Block) ;
    // Displays the block on the screen offsetting it by nX and nY.
    void Display(short nX=0; short nY);
    //Deletes the block from the list.
    bool Delete(Sblock Block);
    // Empties the linked list.
    void Destroy();
   
};

class CFlooredBlocks: public CBlockList {
     RECT m_rcBoundary;   // Holds the playing area
  public:
     void Display();
     short CheckAndRemoveContinuousBlocks(); 
       // Returns the number of lines removed. 
       // This can be used to calculate the score. 
       
     IncrementYabove(short nY); 
       // Helper function for CheckAndRemoveContinuousBlocks 
       // used to drop the blocks above the removed line.
       
     bool IsOccupied(nX,nY);
     // Returns true if the coordinates are occupied.
     
     bool Insert(Sblock Block);
  };

  class CShape:public CBlockList {
     CFlooredBlocks* m_pFlooredBlocks;
public:
     bool CreateRandShape(); 
       // Creates a shape from the build in shapes at random. 
       // This function creates the blocks and gives it the color;

     bool MoveTo(x1,y1);  //Moves the shape to the given coordinates.
     bool MoveRight(); // Moves the shape right. Returns true if successful.
     bool MoveLeft();
     bool MoveDown(); // Moves the shape down. 
     bool Rotate();   // Rotates based on the shape.
     void Display();  // Displays the shape
     
     void ConvertToSpaceCoord(); 
       // Converts the internal SBlock to contain the actual 
       // coordinates so that it can be added to the floored list.
       
     bool SetMaxNoOfShapesAllowed(short nMac); 
       // Sets the maximum number of shapes that 
       // will be used from the array. This way you 
       // can added new shapes to the array and active
       // it by changing this value.
};
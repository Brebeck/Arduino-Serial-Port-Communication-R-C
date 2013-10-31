import processing.serial.*;

Serial port;
boolean[] keys = new boolean[526];
ArrayList pressedKeys;


void setup() {
  size(500, 500);
  port = new Serial(this, "COM7", 9600);
}

void draw() {
  pressedKeys  = new ArrayList();
  for (int x = 0; x < 526; x++) {
    if (keys[x]) {
      println((char)x);
      pressedKeys.add(new Character((char)x));
    }
  }
  if (pressedKeys.size() > 0) {
    for (int x = 0; x < pressedKeys.size(); x++) {
      port.write((Character)pressedKeys.get(x));
    }
  }
  else port.write('z');
  delay(100);
}


boolean checkKey(int k)
{
  if (keys.length >= k) return keys[k];
  return false;
}

void keyPressed()
{ 
  keys[(int)key] = true;
}

void keyReleased()
{ 
  keys[(int)key] = false;
}

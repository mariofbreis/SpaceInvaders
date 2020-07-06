# Space Invaders
 Project for the Computer Graphics course

For those who don't know the game Space Invaders was created by Tomohiro Nishikado for Taito and was launched in 1978.
The player controls a ship that tries to destroy waves of aliens in order to earn as many points as possible.
Over the past 35 years, numerous versions of this game have appeared, including some reimplementations such as original graphics that can be played online. The aim of this project was to recreate this classic in a 3D version.
The idea was to maintain the original gameplay by changing the graphical perspective so that the various elements of the game have a 3D aspect.
The project was divided into 5 parts.

# Part 1
- Define a fixed camera with a top view over the scene using an orthogonal projection (similar to the 2D view of the original game).
- Model the ship, shields and aliens using simple geometric objects (cubes and spheres). Each element must be composed of more than one geometric object.
- Control the movement of the ship with the keyboard using one key to move the ship to the left and another to move the ship to the right.

Functions used: glViewport, glMatrixMode, glOrtho, glTranslate, glRotate, glScale, glPushMatrix, glPopMatrix, glutSolidCube, glutSolidSphere, glutKeyboardFunc

# Part 2
- Define two additional cameras, taking care to keep the previously defined camera. It must be possible to switch between the three cameras using the “1”, “2” and “3” keys. Chamber 2 must use a perspective projection and must be placed behind the ship, following its movement (the ship must be visible). Camera 3 is similar to the previous one, but it must simulate a view in the 1st person (without the ship being visible).
- Detect the intersection of the ship with the limits of the playing area, to prevent the ship from leaving the screen and stop being visible.
- Create the movement of aliens. The aliens must move from row to row, from left to right and then from right to left, then slowly approach the ship, and so on as in the original game.

Functions used: gluPerspective, gluLookAt, glutTimerFunc, glutIdleFunc, glutGet (GLUT_ELAPSED_TIME)

# Part 3
- Create the overall illumination of the scene using a directional light source.
- Define appropriate materials for the ship, shields and aliens. Shields and aliens must have dull (dull) materials. The model of the ship must be replaced by a mesh of polygons and the ship must have a shiny metallic appearance.
- Create the ship's shots. The ship must fire one missile at a time when a key is pressed. For now, the missiles still do not collide with the aliens and must disappear after crossing the screen.

Functions used: glEnable (GL_LIGHTING), glEnable (GL_LIGHTi), glLight, glMaterial, glBegin (GL_TRIANGLES, GL_POLYGON, glEnd, glVertex, glNormal

# Part 4
- Create an alternative light source to the already defined directional light. This light source must be a spotlight that follows the movement of the ship, as if it were a searchlight that points to the aliens that are immediately in front of the ship. As with cameras, it must be possible to use keys to switch between the two lighting modes.
- Place a texture that occupies the entire playing area and serves as a background to the game. This texture must react to the lighting.
- Create the shots of the aliens. The shots must be semi-random, but the aliens can only fire if there are no other aliens in front of them in the respective column. For now, the bullets of the aliens do not collide with the shields and the ship, and should disappear after crossing the screen.

Functions used: glBindTexture, glTexEnvf, glTexParameter, glTexCoord2d, glGenTextures, gluBuild2DMipmaps, rand, srand

# Part 5
- Detect the collisions of the ship's missiles with shields and aliens; the bullets of the aliens with the shields and the ship; and the aliens with the shields and the ship. The ship's missiles “reduce” the shield and eliminate the aliens. The bullets of the aliens "reduce" the shield and take lives from the ship. The aliens completely eliminate the shields when they collide with them. The ship immediately loses all lives when it collides with the aliens or the aliens reach the end of the play area.
- Create a system of simple particles that "pulverizes" the ship when it loses a life or the aliens when they are eliminated. The idea is to make the ship and the aliens disappear in an explosion of small cubes or spheres that disappear from the scene when they hit the ground.
- Create a simple HUD (heads-up display) that shows the number of lives and the score. The score starts at 0 and increases whenever the ship eliminates an alien. The ship has 3 lives.

Functions used: glRasterPos, glutBitmapCharacter, glutStrokeCharacter

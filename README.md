# OpenGL TD Solutions

This repository contains solutions for OpenGL Travaux Dirigés (Tutorial Exercises). The project is organized into exercises and their corresponding solutions, covering fundamental OpenGL concepts and 2D/3D graphics programming.

## 📁 Repository Structure

### Exercises
The `Exercises` folder contains the original exercise files:
- `frontline.cpp` - Front-line rendering exercise
- `house.cpp` - House drawing exercise
- `quadstrip.cpp` - Quad strip primitives
- `trianglestrip.cpp` - Triangle strip primitives

### Solutions
The `Solution` folder contains completed implementations:

#### 2D Graphics Solutions
- `drawSquareOnClick(td5ex1).cpp` - Interactive square drawing on mouse click
- `drawSquareOnClick(td6ex1).cpp` - Enhanced square drawing functionality
- `function(td2ex2).cpp` - Mathematical function plotting
- `gingerBread(td3ex1).cpp` - Gingerbread fractal visualization
- `graph(td3ex2).cpp` - Graph plotting utilities
- `hashtag(td1ex1).cpp` - Simple hashtag symbol drawing
- `setRectangle(td2ex1).cpp` - Rectangle drawing functions
- `village(td1ex2).cpp` - Village scene composition

#### 3D Graphics Solutions
- `3dCube(td6ex3).cpp` - 3D cube rendering and manipulation
- `translateAndRotate(td4ex1).cpp` - 3D transformations (translation and rotation)

#### Advanced Topics
- `polygonChanges(td6ex2).cpp` - Dynamic polygon modifications

## 🚀 Getting Started

### Prerequisites
- C++ compiler (GCC, Clang, or Visual Studio)
- OpenGL development libraries
- GLUT or FreeGLUT for window management
- Basic knowledge of C++ and computer graphics

### Dependencies
Make sure you have the following installed:
```bash
# Ubuntu/Debian
sudo apt-get install freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev

# macOS (using Homebrew)
brew install freeglut

# Windows
# Download and install OpenGL libraries and GLUT
```

### Compilation
To compile any of the solution files:

```bash
# Generic compilation command
g++ -o output_name source_file.cpp -lGL -lGLU -lglut

# Example for 3D cube
g++ -o 3dcube Solution/3dCube\(td6ex3\).cpp -lGL -lGLU -lglut

# Example for interactive square drawing
g++ -o square Solution/drawSquareOnClick\(td5ex1\).cpp -lGL -lGLU -lglut
```

### Running the Programs
After compilation, run the executable:
```bash
./output_name
```

## 📚 Exercise Topics Covered

### TD1 - Basic Drawing
- Simple shape rendering (hashtag, village scene)
- Coordinate systems and basic primitives

### TD2 - Functions and Rectangles
- Mathematical function visualization
- Rectangle drawing utilities
- Coordinate transformations

### TD3 - Fractals and Complex Shapes
- Gingerbread fractal implementation
- Advanced mathematical visualizations

### TD4 - 3D Transformations
- Translation and rotation in 3D space
- Matrix transformations

### TD5 & TD6 - Interactive Graphics
- Mouse event handling
- Interactive shape drawing
- 3D cube manipulation
- Dynamic polygon modifications

## 🎯 Key Learning Objectives

- Understanding OpenGL rendering pipeline
- 2D and 3D coordinate systems
- Primitive drawing (points, lines, triangles, quads)
- Interactive graphics programming
- 3D transformations and projections
- Event handling in graphics applications
- Mathematical visualization techniques

## 📖 Usage Examples

### Drawing Interactive Squares
The `drawSquareOnClick` solutions demonstrate mouse interaction:
- Click to place squares on the screen
- Real-time rendering updates
- Coordinate system mapping

### 3D Cube Rendering
The `3dCube` solution shows:
- 3D object creation
- Perspective projection
- Rotation and viewing transformations

### Mathematical Visualizations
Function plotting examples demonstrate:
- Coordinate system setup
- Mathematical function rendering
- Graph plotting techniques

## 🔧 Troubleshooting

### Common Issues
1. **Compilation Errors**: Ensure OpenGL libraries are properly installed
2. **Window Not Opening**: Check GLUT installation and display settings
3. **Linking Errors**: Verify library flags (-lGL -lGLU -lglut)

### Platform-Specific Notes
- **Linux**: May need to install mesa development packages
- **macOS**: Use Xcode command line tools
- **Windows**: Ensure proper library paths are set

## 📝 Notes

- Each solution file is self-contained and can be compiled independently
- Exercise numbering follows the TD (Travaux Dirigés) format
- Solutions progress from basic 2D graphics to advanced 3D manipulations
- Code includes comments explaining key OpenGL concepts

## 🤝 Contributing

If you find improvements or have additional solutions:
1. Fork the repository
2. Create a feature branch
3. Add your solutions with appropriate documentation
4. Submit a pull request

## 📄 License

This project is licensed under the terms specified in the LICENSE file.

---

**Note**: This repository is for educational purposes, designed to help students learn OpenGL programming concepts through practical exercises.
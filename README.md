# Moonlight Engine
The moonlight engine is a high-performance game engine for Windows and C++.

## Building
#### 1) Clone the repository
```bash
git clone --recursive https://github.com/Todegal/Moonlight.git
```
#### 2) Go through all the dependency folders and generate the projects
Note: You don't need to generate the project for `glad`
#### 3) Add the built projects to `Moonlight.sln`
#### 4) Add the following post-build command to all the dependency projects
```
mkdir "$(SolutionDir)Dependencies\lib(x64)\$(Configuration)\"
copy /Y "$(OutDir)$(TargetName).lib" "$(SolutionDir)Dependencies\lib(x64)\$(Configuration)\$(TargetName).lib"
```
#### 5) Make a project which links to `Moonlight.lib` and paste `Moonlight.dll` into your executable folder
#### 6) alternatively copy and rename the `Sandbox` project
© Copyright Niall Townley 2019
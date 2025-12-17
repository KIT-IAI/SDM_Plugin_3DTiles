# 3DTiles Plugin
The 3DTiles Plugin for the [KITModelViewer](https://github.com/KIT-IAI/SDM_KITModelViewer) downloads and displays geographical 3DTiles Data from the Google Maps Tile API.

The plugin is based on the open plugin interface. To be able to create the plugin, the plugin SDK is required. Simply copy the content of the current SDK version into the plugin folder.

 
Based on [3DTilesDownloader](https://github.com/qq1469617613/3DTilesDownloader).

![KIT CN](https://github.com/KIT-IAI/SDM_Plugin_3DTiles/blob/main/3dtiles-plugin-example.png?raw=true)

## Usage

Load some georeferenced file and start the plugin. The plugin will automatically detect the location and size of the current model and downloads the corresponding 3dtiles.
The 3dtiles are downloaded via the Google Maps Tile API.<br> 
![3dtiles-plugin](https://github.com/KIT-IAI/SDM_Plugin_3DTiles/blob/main/3dtiles-plugin-interface.png?raw=true)


## Dependencies

In order to access the Google Maps Tile API a valid api key is required. Enter the api key in Options->WebServices->Google 3D Tiles.
Note: Google Maps Tile API is a free API but keys generated after 2025 might not be valid in the EU due to a legal conflict with Google and the EU. 
You need to enable the Maps Tile API and the elevation API. 


## Building the project
The project is structured into a plugin for the KITModelViewer written in C++ and the 3dtilesdownloader written in Python. 
The plugin can be build with cmake and vcpkg. 
In order for the plugin to run you need to compile the 3dtilesdownloader into an executable. The easiest way is to create a venv, install the required packages, and then build the executable.

1. Navigate to 3dtiles-plugin/3dtilesdownloader
2. create a venv in the directory `python -m venv venv`
3. activate the venv `venv\Scripts\activate`
4. install the requirements from requirements.txt `pip install -r requirements.txt`
5. run the command `pyinstaller main.py` to build the executable
6. copy the resulting `main.exe` and the `_internal` Folder into the directory of the plugin, `plugins/3dtilesplugin/` 

## Dependencies

### Use of vcpkg:

|Package Name         |Install Command                            |
|:---                 |:---                                       |
|fmt                  |vcpkg install fmt triplet=x64-windows   
|wxwidgets            |vcpkg install wxwidgets triplet=x64-windows    

### Python
In order to build the python files into an executable Python is needed

## How to cite

```bibtex
@software{SDM_Plugin_3DTiles,
	title        = {SDM_Plugin_3DTiles},
	author       = {{Timothy Steven Schürstädt}},
	url          = {https://github.com/KIT-IAI/SDM_Plugin_3DTiles},
	date         = {2025}
}
```

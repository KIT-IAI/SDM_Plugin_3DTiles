import ifcdb
from scripts.get_tileset import download_tileset
import numpy as np

document = ifcdb.get_document()


#lon,lat = 8.305749, 47.052138


if document.get_latlon_boundingbox():
    document.log_message('Downloading...')
    
    x1 = document.get_latlon_boundingbox()[0][0]
    y1 = document.get_latlon_boundingbox()[0][1]

    x2 = document.get_latlon_boundingbox()[1][0]
    y2 = document.get_latlon_boundingbox()[1][1]


    latlon = np.array([[x1, y1], [x2, y2]])

    document.log_message(latlon)

    center = latlon.mean(axis=0)
    radius = np.linalg.norm(latlon)


    download_tileset(center[1],
                     center[0],
                     radius,
                     api_key = 'AIzaSyA-1mxnxXSovYO9-V1b-onQR2QrFjzQLLg',
                     output_path = document.get_data_path() + '/3dtiles',
                     thread_count=30)


    document.log_message('Data saved in: ' + document.get_data_path() + '/3dtiles')
    document.log_message("all done")
else:
    document.log_message("no georeference found")
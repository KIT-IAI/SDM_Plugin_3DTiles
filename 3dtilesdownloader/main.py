from scripts.get_tileset import download_tileset
import sys

#lon,lat = 8.305749, 47.052138
#radius = 65
# download_tileset(lon,
#                  lat,
#                  100,
#                  api_key = "enter-api-key-here",
#                  output_path = "C:\\Users\\no9964\\Documents\\3DTilesDownloader-main\\resultnew2",
#                  clip_checkbox="1",
#                  thread_count=30)



#arguments
#lat
#lon
#radius
#api key
#output_path
#clip to model bounding box (bool)

download_tileset(float(sys.argv[1]),
                 float(sys.argv[2]),
                 float(sys.argv[3]),
                 api_key = sys.argv[4],
                 output_path = sys.argv[5],
                 clip_checkbox = sys.argv[6],
                 thread_count=30)

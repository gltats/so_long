from PIL import Image

# create a new image with a solid color
image = Image.new('RGB', (100, 100), color=(255, 255, 255))

# save the image as an XPM file
image.save('example.xpm', format='XPM')
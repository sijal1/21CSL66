#7.Write a Program to read a digital image. Split and display image into 4 quadrants, up, down, right and left.

import cv2

# Read the image
image = cv2.imread('1.jpg')  # Change this to the path of your image
if image is None:
    print("Error: Could not read the image.")
else:
    # Get the dimensions of the image
    height, width = image.shape[:2]
    # Calculate the midpoints
    mid_x = width // 2
    mid_y = height // 2
    # Split the image into four quadrants
    top_left = image[0:mid_y, 0:mid_x]
    top_right = image[0:mid_y, mid_x:width]
    bottom_left = image[mid_y:height, 0:mid_x]
    bottom_right = image[mid_y:height, mid_x:width]
    # Save each quadrant as an image file
    cv2.imwrite('top_left.jpg', top_left)
    cv2.imwrite('top_right.jpg', top_right)
    cv2.imwrite('bottom_left.jpg', bottom_left)
    cv2.imwrite('bottom_right.jpg', bottom_right)
    print("Quadrants saved successfully.")

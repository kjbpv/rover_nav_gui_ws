# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from rover_msgs/NavState.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class NavState(genpy.Message):
  _md5sum = "b2c76c6eb34da44397368c49a4c56269"
  _type = "rover_msgs/NavState"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """float32[3] position	# north, east, hieght (m)
float32 Vw		# wheelspeed (m/s)
float32 phi		# Roll angle (rad)
float32 theta		# Pitch angle (rad)
float32 psi		# Yaw angle (rad)
float32 chi		# Course angle (rad)
float32 p		# Body frame rollrate (rad/s)
float32 q		# Body frame pitchrate (rad/s)
float32 r		# Body frame yawrate (rad/s)
float32 Vg		# Groundspeed (m/s)
float64 base_latitude   # Latitude [degrees]. Positive is north of equator; negative is south.
float64 base_longitude  # Longitude [degrees]. Positive is east of prime meridian; negative is west.
float64 base_altitude   # Altitude [m]. Positive is above the WGS 84 ellipsoid

"""
  __slots__ = ['position','Vw','phi','theta','psi','chi','p','q','r','Vg','base_latitude','base_longitude','base_altitude']
  _slot_types = ['float32[3]','float32','float32','float32','float32','float32','float32','float32','float32','float32','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       position,Vw,phi,theta,psi,chi,p,q,r,Vg,base_latitude,base_longitude,base_altitude

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(NavState, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.position is None:
        self.position = [0.,0.,0.]
      if self.Vw is None:
        self.Vw = 0.
      if self.phi is None:
        self.phi = 0.
      if self.theta is None:
        self.theta = 0.
      if self.psi is None:
        self.psi = 0.
      if self.chi is None:
        self.chi = 0.
      if self.p is None:
        self.p = 0.
      if self.q is None:
        self.q = 0.
      if self.r is None:
        self.r = 0.
      if self.Vg is None:
        self.Vg = 0.
      if self.base_latitude is None:
        self.base_latitude = 0.
      if self.base_longitude is None:
        self.base_longitude = 0.
      if self.base_altitude is None:
        self.base_altitude = 0.
    else:
      self.position = [0.,0.,0.]
      self.Vw = 0.
      self.phi = 0.
      self.theta = 0.
      self.psi = 0.
      self.chi = 0.
      self.p = 0.
      self.q = 0.
      self.r = 0.
      self.Vg = 0.
      self.base_latitude = 0.
      self.base_longitude = 0.
      self.base_altitude = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_struct_3f.pack(*self.position))
      _x = self
      buff.write(_struct_9f3d.pack(_x.Vw, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.base_latitude, _x.base_longitude, _x.base_altitude))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      start = end
      end += 12
      self.position = _struct_3f.unpack(str[start:end])
      _x = self
      start = end
      end += 60
      (_x.Vw, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.base_latitude, _x.base_longitude, _x.base_altitude,) = _struct_9f3d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(self.position.tostring())
      _x = self
      buff.write(_struct_9f3d.pack(_x.Vw, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.base_latitude, _x.base_longitude, _x.base_altitude))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(_x))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(_x))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      start = end
      end += 12
      self.position = numpy.frombuffer(str[start:end], dtype=numpy.float32, count=3)
      _x = self
      start = end
      end += 60
      (_x.Vw, _x.phi, _x.theta, _x.psi, _x.chi, _x.p, _x.q, _x.r, _x.Vg, _x.base_latitude, _x.base_longitude, _x.base_altitude,) = _struct_9f3d.unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_9f3d = struct.Struct("<9f3d")
_struct_3f = struct.Struct("<3f")